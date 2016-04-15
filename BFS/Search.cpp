//
//  Search.cpp
//  PushBox
//
//  Created by xuyi on 4/15/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include "Search.h"
#include <stack>

using namespace std;


ostream & operator<<(ostream & os, const Point & pos)
{
    os<<"["<<pos._x<<","<<pos._y<<"]";
    
    return os;
}

int Search::BFS()
{
    Node node(0,0,0);
    queue<Node> q;
    while(!q.empty())
    {
        q.pop();
    }
    
    q.push(node);
    
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        
        if(node.x == maxn-1 && node.y == maxn-1)
        {
            return node.step;
        }
        
        visit[node.x][node.y] = 1;  //初始位置 
        for(int i = 0; i < 4; i++)
        {
            int x = node.x + stepArr[i][0];
            int y = node.y + stepArr[i][1];
            
            if(x >= 0 && y >= 0 && x < maxn && y < maxn && visit[x][y] == 0 && mazeArr[x][y] == 0)
            {
                visit[x][y] = 1;
                Node next(x, y, node.step + 1);
                q.push(next);
            }
        }
    }
    
    return -1;
}

bool Search::IsWay(Point pos)
{
    bool ret = false;
    
    if(pos._x >= 0 && pos._y >= 0 && pos._x < maxn && pos._y < maxn && visit[pos._x][pos._y] == 0 && mazeArr[pos._x][pos._y] == 0)
    {
        ret = true;
    }
    
    return ret;
}

// pos : 箱子位置
bool Search::SearchBoxWay(Point curPos, Point goalPos)
{
    static stack<Point> posStack;
    posStack.push(curPos);
    
//    cout<<"push:"<<curPos;
    
    visit[curPos._x][curPos._y] = 1;
    
    { // 四个方向查找是否有出路
        bool goodWay = false;
        for(int i = 0; i < 4; i++)
        {
            int x = curPos._x + stepArr[i][0];
            int y = curPos._y + stepArr[i][1];
            
            /*
            if(IsGoal(curPos))
            {
                goodWay = true;
                
                return true;
            }
             */
            
            
            // 找到目标
            if(curPos == goalPos)
            {
                cout<<endl;
//                cout<<"cur: "<<curPos<<"goal"<<goalPos<<endl;
                while (!posStack.empty())
                {
                    cout<<posStack.top();
                    posStack.pop();
                    
                }
                
                return true;
            }
            
            Point nextPos(x, y);
            if(IsWay(nextPos))
            {
                // 无路弹出当前位置
                if(!SearchBoxWay(nextPos, goalPos))
                {
                    posStack.pop();
                }
                else
                {
                    goodWay = true;
                }
            }
        }
        
        // 无路可走
        if(!goodWay)
        {
            return false;
        }
    }
    
    return true;
}

void Search::FindWay()
{
    SearchBoxWay(Point(0, 0), Point(4, 4));
}
