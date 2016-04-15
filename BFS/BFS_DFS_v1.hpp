//
//  BFS_DFS_v1.hpp
//  PushBox
//
//  Created by xuyi on 4/15/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#ifndef BFS_DFS_v1_h
#define BFS_DFS_v1_h


#include <list>
#include <vector>
#include <set>
#include <ext/hash_set>
using std::list;
using std::vector;
using std::set;
using __gnu_cxx::hash_set;
using __gnu_cxx::hash;

// 仿函式，用于不检查状态结点是否重复，搜索算法的两参数版本使用
template <class T>
struct NoCheckDup : std::unary_function<T, bool>
{
    bool operator() (const T&) const
    {
        return false;
    }
};
// 仿函式，用hash_set容器检查状态结点是否重复
// 要求状态类提供operator==以及hash函数
template <class T, class HashFcn = hash<T> >
class HashCheckDup : std::unary_function<T, bool>
{
    typedef hash_set<T, HashFcn> Cont;
    Cont states_;
public:
    typedef typename Cont::hasher hasher;
    HashCheckDup(const hasher& hf) : states_(100, hf) {}
    bool operator() (const T& s)
    {
        if (states_.find(s) != states_.end())  // 状态已存在，重复
        {
            return true;
        }
        states_.insert(s);  // 状态未重复，记录该状态
        return false;
    }
};

// 仿函式，用set容器检查状态结点是否重复
// 要求状态类提供operator<
template <class T>
class OrderCheckDup : std::unary_function<T, bool>
{
    typedef set<T> Cont;
    Cont states_;
public:
    bool operator() (const T& s)
    {
        typename Cont::iterator i = states_.find(s);
        if (i != states_.end())  // 状态已存在，重复
        {
            return true;
        }
        states_.insert(i, s);  // 状态未重复，记录该状态
        return false;
    }
};

// 仿函式，用vector容器检查状态结点是否重复，线性复杂度
// 要求状态类提供operator==
template <class T>
class SequenceCheckDup : std::unary_function<T, bool>
{
    typedef vector<T> Cont;
    Cont states_;
public:
    bool operator() (const T& s)
    {
        typename Cont::iterator i =
        find(states_.begin(), states_.end(), s);
        if (i != states_.end())  // 状态已存在，重复
        {
            return true;
        }
        states_.push_back(s);  // 状态未重复，记录该状态
        return false;
    }
};

// 两参数版本
// initState : 初始化状态，类T1应提供成员函数nextStep()和isTarget()，
//             nextStep()用vector<T1>返回下一步可能的所有状态，
//             isTarget()用于判断当前状态是否符合要求的答案；
// afterFindSolution : 仿函式，在找到一个有效答案后调用之，它接受一个const T1&，
//                     并返回一个Boolean值，true表示停止搜索，false表示继续找
// return : 找到的答案数量
template <class T1, class T2 >
int BreadthFirstSearch(const T1& initState, const T2& afterFindSolution)
{
    NoCheckDup<T1> noCheckDup;
    return BreadthFirstSearch(initState, afterFindSolution, noCheckDup);
}

// 三参数版本，前两个参数参考两参数版本说明
// checkDup :  仿函式，对于每一个下一步可能的状态调用之，它接受一个const T1&，
//             并返回一个Boolean值，true表示状态重复，false表示状态不重复
//             checkDup的缺省值是不进行检查，假定所有生成的状态均不会重复
// return : 找到的答案数量
template <class T1, class T2, class T3 >
int BreadthFirstSearch(const T1& initState, const T2& afterFindSolution, T3& checkDup)
{
    int n = 0;
    list<T1> states;
    states.push_back(initState);
    vector<T1> nextStates;
    
    bool stop = false;
    typename list<T1>::iterator head = states.begin();  //指向下个搜索的结点
    while (!stop && head != states.end())
    {
        T1 state = *head;  //搜索一个结点
        nextStates.clear();
        state.nextStep(nextStates);  //从搜索点生成下一层结点
        
        for (typename vector<T1>::iterator i = nextStates.begin(); i != nextStates.end(); ++i)
        {
            if (i->isTarget())
            {  // 找到一个目标状态
                ++n;
                if (stop = afterFindSolution(*i))  // 处理结果并决定是否停止
                {
                    break;
                }
            }
            else
            {  // 不是目标状态，判断是否放入搜索队列中
                if (!checkDup(*i))  // 只将不重复的状态放入搜索队列
                {
                    states.push_back(*i);
                }
            }
        }
        ++head;  //指针移到下一个元素
    }
    return n;
}

template <class T1, class T2 >
int DepthFirstSearch(const T1& initState, const T2& afterFindSolution)
// 两参数版本
// initState : 初始化状态，类T1应提供成员函数nextStep()和isTarget()，
//             nextStep()用vector<T1>返回下一步可能的所有状态，
//             isTarget()用于判断当前状态是否符合要求的答案；
// afterFindSolution : 仿函式，在找到一个有效答案后调用之，它接受一个const T1&，
//                     并返回一个Boolean值，true表示停止搜索，false表示继续找
// return : 找到的答案数量
{
    NoCheckDup<T1> noCheckDup;
    return DepthFirstSearch(initState, afterFindSolution, noCheckDup);
}

template <class T1, class T2, class T3 >
int DepthFirstSearch(const T1& initState, const T2& afterFindSolution,
                     T3& checkDup)
// 三参数版本，前两个参数参考两参数版本说明
// checkDup :  仿函式，对于每一个下一步可能的状态调用之，它接受一个const T1&，
//             并返回一个Boolean值，true表示状态重复，false表示状态不重复
//             checkDup的缺省值是不进行检查，假定所有生成的状态均不会重复
// return : 找到的答案数量
{
    int n = 0;
    list<T1> states;
    states.push_back(initState);
    typename list<T1>::iterator head = states.begin();  //指向下个搜索的结点
    vector<T1> nextStates;
    bool stop = false;
    while (!stop && head != states.end())
    {
        T1 s = *head;
        nextStates.clear();
        s.nextStep(nextStates);
        for (typename vector<T1>::iterator i = nextStates.begin();
             i != nextStates.end(); ++i)
        {
            if (i->isTarget())
            {  // 找到一个目标状态
                ++n;
                if (stop = afterFindSolution(*i))  // 处理结果并决定是否停止
                {
                    break;
                }
            } else {  // 不是目标状态，判断是否放入搜索队列中
                if (!checkDup(*i))  // 只将不重复的状态放入搜索队列
                {
                    typename list<T1>::iterator it = head;
                    states.insert(++it, *i);  //插入到head的后面
                }
            }
        }
        ++head;
    }
    return n;
}

#endif /* BFS_DFS_v1_h */
