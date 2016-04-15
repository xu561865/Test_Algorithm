//
//  SimpleSelectionSort.cpp
//  Test_Algorithm
//
//  Created by xuyi on 4/15/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include <iostream>


void print(int a[], int n ,int i)
{
    std::cout<<"第"<<i+1 <<"趟 : ";
    for(int j= 0; j<8; j++)
    {
        std::cout<<a[j] <<"  ";
    }
    
    std::cout<<std::endl;
  }
/**
* 数组的最小值
*
* @return int 数组的键值
*/
int SelectMinKey(int a[], int n, int i)
{
    int k = i;
    for(int j=i+1 ;j< n; ++j)
    {
        if(a[k] > a[j]) k = j;
    }
    return k;
}

/**
* 选择排序
*
*/
void selectSort(int a[], int n)
{
    int key, tmp;
    for(int i = 0; i < n; ++i)
    {
        key = SelectMinKey(a, n,i);           //选择最小的元素
        if(key != i)
        {
            tmp = a[i];  a[i] = a[key]; a[key] = tmp; //最小元素与第i位置元素互换
        }
        print(a,  n , i);
    }
}