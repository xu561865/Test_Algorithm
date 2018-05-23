//
//  MaxSubArray.cpp
//  Test_Algorithm
//
//  Created by xuyi on 23/05/2018.
//  Copyright © 2018 xuyi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "MaxSubArray.h"

int MaxSubArray::GetMaxSubArray()
{
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int max = MaxSubArray::helper(a, 8);
    std::cout<<max<<std::endl;
    return max;
}

int MaxSubArray::helper(int a[], int size)
{
    if (size<=0) return 0;
    int sum = 0;
    int max = - (1 << 31);
    int cur = 0;
    
    while (cur < size)
    {
        sum += a[cur++];
        if (sum > max)
        {
            max = sum;
        }
        else if (sum < 0)
        {
            sum = 0;
        }
    }
    
    return max;
}

