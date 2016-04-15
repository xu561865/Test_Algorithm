//
//  SokoState_v1.cpp
//  PushBox
//
//  Created by xuyi on 4/15/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include <iterator>
#include <string>
#include <memory>
#include <stdexcept>
#include "SokoState_v1.h"

using namespace std;

inline unsigned char SokoState::mapChar(Point p) const
{
    if (isWall(p))
        return CharWall;
    else if (isBox(p))
        return isDest(p) ? CharInDest : CharBox;
    else if (isSoko(p))
        return isDest(p) ? CharSokoInDest : CharSoko;
    else if (isDest(p))
        return CharDest;
    else
        return CharSpace;
}

void SokoState::checkSoko(stack<Point>& ps, Point p)
{
    if (isPureSpace(p))
    {
        map_[p.x_][p.y_] |= FlagSoko;
        ps.push(p);
    }
}

void SokoState::stateEq()
{
    int i, j;
    for (i = 1; i < rows_-1; i++)
    {
        for (j = 1; j < cols_-1; j++)
        {
            if (isSoko(Point(i, j))) break;
        }
        if (j < cols_-1) break;
    }
    
    stack<Point> points;
    Point p(i, j);
    points.push(p);
    
    while (!points.empty())
    {
        p = points.top();
        points.pop();
        checkSoko(points, p.up());
        checkSoko(points, p.down());
        checkSoko(points, p.left());
        checkSoko(points, p.right());
    }
}

bool SokoState::moveBox(SokoState& r, Point box, Point soko, Point nBox, char d) const
{
    if (!isSoko(soko) || !isSpace(nBox))
        return false;
    
    r = *this;
    for (int i = 0; i < r.rows_; i++)  //清除soko标志
    {
        for (int j = 0; j < r.cols_; j++)
        {
            r.map_[i][j] &= ~FlagSoko;
        }
    }
    r.map_[box.x_][box.y_] &= ~FlagBox;  //移动箱子
    r.map_[box.x_][box.y_] |= FlagSoko;
    r.map_[nBox.x_][nBox.y_] |= FlagBox;
    r.stateEq();
    r.steps_.push_back(SokoStep(box.x_, box.y_, d));
    return true;
}

void SokoState::nextStep(vector<SokoState>& vs) const
{
    SokoState newState;
    for (int i = 1; i < rows_-1; i++)
    {
        for (int j = 1; j < cols_-1; j++)
        {
            Point p(i, j);
            if (!isBox(p))
            {
                continue;
            }
            
            if (moveBox(newState, p, p.down(), p.up(), 'U'))
                vs.push_back(newState);
            if (moveBox(newState, p, p.up(), p.down(), 'D'))
                vs.push_back(newState);
            if (moveBox(newState, p, p.right(), p.left(), 'L'))
                vs.push_back(newState);
            if (moveBox(newState, p, p.left(), p.right(), 'R'))
                vs.push_back(newState);
        }
    }
}

bool SokoState::isTarget() const
{
    for (int i = 1; i < rows_-1; i++)
    {
        for (int j = 1; j < cols_-1; j++)
        {
            Point p(i, j);
            if (isDest(p) != isBox(p))
                return false;
        }
    }
    return true;
}

void SokoState::printAnswer(ostream& os) const
{
    copy(steps_.begin(), steps_.end(), ostream_iterator<SokoStep>(os, " "));
    
#if 0
    // translate
    for(auto step : steps_)
    {
        int temp = step.x_;
        step.x_ = step.y_;
        step.y_ = temp;
        
        step.x_++;
        step.y_++;
    }
    
    copy(steps_.begin(), steps_.end(), ostream_iterator<SokoStep>(os, " "));
#endif
}

bool SokoState::operator< (const SokoState& other) const
{
    if (rows_ < other.rows_)
        return true;
    if (rows_ > other.rows_)
        return false;
    if (cols_ < other.cols_)
        return true;
    if (cols_ > other.cols_)
        return false;
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            if (map_[i][j] < other.map_[i][j])
                return true;
            if (map_[i][j] > other.map_[i][j])
                return false;
        }
    }
    return false;
}

ostream& operator<< (ostream& os, const SokoState& s)
{
    for (int i = 0; i < s.rows_; i++)
    {
        for (int j = 0; j < s.cols_; j++)
        {
            os << s.mapChar(SokoState::Point(i, j));
        }
        os << "\n";
    }
    os << "------------------------" << endl;
    return os;
}

istream& operator>> (istream& is, SokoState& s)
{
    is >> s.rows_;
    if (s.rows_ < MIN_ROWS || s.rows_ > MAX_ROWS)
    {
        throw invalid_argument("rows of soko game error.");
    }
    is >> s.cols_;
    if (s.cols_ < MIN_COLS || s.cols_ > MAX_COLS)
    {
        throw invalid_argument("cols of soko game error.");
    }
    
    string str;
    getline(is, str);  // 滤过第一行的换行
    for (int i = 0; i < s.rows_; i++)
    {
        getline(is, str);
        for (int j = 0; j < s.cols_; j++)
        {
            s.map_[i][j] = 0;
            switch (str[j]) {
                case SokoState::CharBox :
                    s.map_[i][j] |= SokoState::FlagBox;
                    break;
                case SokoState::CharWall :
                    s.map_[i][j] |= SokoState::FlagWall;
                    break;
                case SokoState::CharSpace :
                    break;
                case SokoState::CharDest :
                    s.map_[i][j] |= SokoState::FlagDest;
                    break;
                case SokoState::CharInDest :
                    s.map_[i][j] |= SokoState::FlagDest | SokoState::FlagBox;
                    break;
                case SokoState::CharSoko :
                    s.map_[i][j] |= SokoState::FlagSoko;
                    break;
                case SokoState::CharSokoInDest :
                    s.map_[i][j] |= SokoState::FlagSoko | SokoState::FlagDest;
                    break;
                default :
                    throw invalid_argument(
                                           string("char of soko game error: ") + str );
            }
        }
    }
    s.stateEq();
    return is;
}
