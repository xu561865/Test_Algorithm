//
//  BubbleSort.cpp
//  Test_Algorithm
//
//  Created by 徐以 on 07/01/2017.
//  Copyright © 2017 xuyi. All rights reserved.
//

#include "BubbleSort.h"
#include <iostream>

void swap(int & n1, int & n2)
{
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void BubbleSort::sort(int a[], int n)
{
    for(int i = n - 1; i >= 0; --i)
    {
        for(int j = 0; j <= i; ++j)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void BubbleSort::print(int a[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout<<a[i]<<" ";
    }
}
