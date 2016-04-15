//
//  Search.hpp
//  PushBox
//
//  Created by xuyi on 4/15/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#ifndef Search_hpp
#define Search_hpp

#include <queue>
#include <iostream>
using namespace std;

#define maxn 9

struct Node
{
    Node(int x1,int y1,int step1):x(x1),y(y1),step(step1){}
    
    int x;
    int y;
    int step;
};

struct Point
{
    Point(){};
    Point(int x, int y) : _x(x), _y(y){}
    bool operator==(Point pos)
    {
        if(pos._x == _x && pos._y == _y)
        {
            return true;
        }
        
        return false;
    }
    
    friend ostream & operator<<(ostream & os, const Point & pos);
    
    int _x;
    int _y;
};

class Search
{
public:
    int BFS();
    
    void SetGoal(Point pos)
    {
        goal._x = pos._x;
        goal._y = pos._y;
    }
    
    bool IsGoal(Point pos)
    {
        bool ret = false;
        
        
        return ret;
        
    }
    
    bool IsWay(Point pos);
    
    void FindWay();
    bool SearchBoxWay(Point pos, Point goalPos);
    
    
private:
    Point goal;
    
    int stepArr[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; //表示上下左右4个方向
    int mazeArr[maxn][maxn] =
    {
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0}
        
    }; //表示的是01矩阵，0：无障碍物， 1：有障碍物
    int visit[maxn][maxn] = {0}; //表示该点是否被访问过，防止回溯，回溯很耗时。
};

#endif /* Search_hpp */
