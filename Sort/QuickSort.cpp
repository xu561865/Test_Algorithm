//
//  QuickSort.cpp
//  Test_Algorithm
//
//  Created by xuyi on 4/14/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include <stdio.h>

void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    
    int first = low;
    int last = high;
    int key = a[first];
    
    while(first < last)
    {
        while(a[last] >= key && first < last)
        {
            last--;
        }
        a[first] = a[last];
        
        while(a[first] <= key && first < last)
        {
            first++;
        }
        
        a[last] = a[first];
        
    }
    
    a[first] = key;
    Qsort(a, low, first - 1);
    Qsort(a, first + 1, high);
}



