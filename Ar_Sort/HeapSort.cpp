//
//  HeapSort.cpp
//  Test_Algorithm
//
//  Created by 徐以 on 6/7/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include <stdio.h>
#include "HeapSort.h"

void AdjustHeap(int H[], int s, int length)
{
    int tmp = H[s];
    int childIndex = s * 2 + 1;
    
    while(childIndex < length)
    {
        if(childIndex + 1 < length && H[childIndex] < H[childIndex + 1])
        {
            childIndex++;
        }
        
        if(H[s] < H[childIndex])
        {
            H[s] = H[childIndex];
            s = childIndex;
            childIndex = childIndex * 2 + 1;
            H[s] = tmp;
        }
        else
        {
            break;
        }
    }
}

void CreateBiggestHeap(int H[], int length)
{
    for(int i = (length - 1) / 2; i >= 0; i--)
    {
        AdjustHeap(H, i, length);
    }
}
