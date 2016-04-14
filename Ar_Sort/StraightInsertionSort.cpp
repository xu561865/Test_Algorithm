//
//  StraightInsertionSort.cpp
//  Test_Algorithm
//
//  Created by xuyi on 4/14/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include <iostream>
#include "StraightInsertionSort.h"

void print(int a[], int n ,int i)
{
    std::cout<<i <<":";
    for(int j = 0; j < 8; j++)
    {
        std::cout<<a[j] <<" ";
    }
    
    std::cout<<std::endl;
}


void StraightInsertionSort::insertSort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        if(a[i] < a[i-1])
        {
            //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
              int guardValue = a[i];        //复制为哨兵，即存储待排序元素
//              a[i] = a[i-1];           //先后移一个元素
            
              int j= i-1;
              while(guardValue < a[j])
              {
                  //查找在有序表的插入位置
                  a[j+1] = a[j];
                  
                  //元素后移
                  if(--j < 0)
                  {
                      break;
                  }
              }
            
              a[j+1] = guardValue;      //插入到正确位置
        }
        
        print(a,n,i);           //打印每趟排序的结果
    }
}