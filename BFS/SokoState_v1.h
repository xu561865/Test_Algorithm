//
//  SokoState_v1.h
//  PushBox
//
//  Created by xuyi on 4/15/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#ifndef SokoState_v1_h
#define SokoState_v1_h


#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::stack;
using std::ostream;
using std::istream;
const int MIN_ROWS = 4;
const int MAX_ROWS = 16;
const int MIN_COLS = 4;
const int MAX_COLS = 16;
class SokoState
{
public:
    SokoState() : rows_(0), cols_(0) {}
    void nextStep(vector<SokoState>&) const;
    bool isTarget() const;
    bool operator< (const SokoState& other) const;
    friend ostream& operator<< (ostream& os, const SokoState& s);
    friend istream& operator>> (istream& is, SokoState& s);
    void printAnswer(ostream& os) const;
private:
    struct Point
    {
        int x_, y_;
        Point(int x, int y) : x_(x), y_(y) {}
        Point up() const { return Point(x_-1, y_); }
        Point down() const { return Point(x_+1, y_); }
        Point left() const { return Point(x_, y_-1); }
        Point right() const { return Point(x_, y_+1); }
    };
    enum MapChar {
        CharWall = 'W',         // Wall障碍物
        CharBox = 'B',          // Box箱子，不在目的地
        CharSpace = 'S',        // Space空地，没有任何东西
        CharDest = 'D',         // Dest目的地
        CharInDest = 'I',       // 已放在目的地上的箱子
        CharSoko = 'K',         // Soko推箱子的人，不在目的地
        CharSokoInDest = 'O',   // Soko推箱子的人，恰好在目的地
        CharError = 'E'         // 错误状态
    };
    enum MapFlag {
        FlagWall = 0x01,    // 是否障碍物
        FlagBox = 0x02,     // 是否有箱子
        FlagDest = 0x04,    // 是否目的地
        FlagSoko = 0x08     // 是否有人
    };
    bool isWall(Point p) const
    { return (map_[p.x_][p.y_] & FlagWall) != 0; }
    bool isBox(Point p) const
    { return (map_[p.x_][p.y_] & FlagBox) != 0; }
    bool isDest(Point p) const
    { return (map_[p.x_][p.y_] & FlagDest) != 0; }
    bool isSoko(Point p) const
    { return (map_[p.x_][p.y_] & FlagSoko) != 0; }
    bool isSpace(Point p) const
    { return !isWall(p) && !isBox(p); }
    bool isPureSpace(Point p) const
    { return isSpace(p) && !isSoko (p); }
    unsigned char mapChar(Point p) const;
    bool moveBox(SokoState& r, Point box, Point soko, Point nBox,
                 char d) const;
    void checkSoko(stack<Point>& ps, Point p);
    void stateEq();
    struct SokoStep  //用于记录每一步箱子的移动
    {
        int x_;
        int y_;
        char d_;  // direction: R,L,U,D
        SokoStep(int x, int y , char d) : x_(x), y_(y), d_(d) {}
        friend ostream& operator<< (ostream& os, const SokoStep& s)
        {
            os << "[" << s.y_ + 1 << ", " << s.x_ + 1<< ", " << s.d_ << "]";
            return os;
        }
    };
    int rows_, cols_;
    unsigned char map_[MAX_ROWS][MAX_COLS];
    vector<SokoStep> steps_;
};

#endif /* SokoState_v1_h */
