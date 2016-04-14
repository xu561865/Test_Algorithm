//
//  ShellInsertSort.cpp
//  Test_Algorithm
//
//  Created by xuyi on 4/14/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include <iostream>
#include "ShellInsertSort.h"

static void print(int a[], int n ,int i)
{
    std::cout<<i <<":";
    for(int j= 0; j<8; j++)
    {
        std::cout<<a[j] <<" ";
    }
    
    std::cout<<std::endl;
}

static void print(int a[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout<<a[i]<<" ";
    }
    
    std::cout<<std::endl;
}

/**
* 直接插入排序的一般形式
*
* @param int dk 缩小增量，如果是直接插入排序，dk=1
*
*/

void insertSort(int a[], int n, int dk)
{
    for(int i = dk; i < n; ++i)
    {
        if(a[i - dk] > a[i])
        {
            //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
            
            int guardValue = a[i];           //复制为哨兵，即存储待排序元素
//            a[i] = a[i-dk];         //首先后移一个元素
            
            int j = i - dk;
            while(a[j] > guardValue)
            {
                //查找在有序表的插入位置
                a[j + dk] = a[j];
                j -= dk;             //元素后移
            }
            
            a[j + dk] = guardValue;            //插入到正确位置
        }
        
//        print(a, n,i );
    }
}

/**
* 先按增量d（n/2,n为要排序数的个数进行希尔排序
*
*/
void ShellInsertSort::sort(int a[], int n)
{
    int dk = n/2;
    while( dk >= 1 )
    {
        insertSort(a, n, dk);
        dk = dk/2;
    }
    
    print(a, n);
}