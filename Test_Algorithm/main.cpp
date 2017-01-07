//
//  main.cpp
//  Test_Algorithm
//
//  Created by xuyi on 4/14/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include "StraightInsertionSort.h"

#include <iostream>
#include "ShellSort.h"
#include "QuickSort.h"
#include <string>
#include "HeapSort.h"
#include "PancakeSort.h"
#include "BubbleSort.h"
#include <vector>



int main(int argc, const char * argv[]) {
    int a[] = {2, 4, 3, 6, 5, 8, 7};
    
    BubbleSort bsort;
    bsort.sort(a, 7);
    bsort.print(a, 7);
    
#ifdef HEAP
    int a[] = {2, 4, 3, 6, 5, 8, 7};
    int length = sizeof(a) / sizeof(a[0]);
    CreateBiggestHeap(a, length);
    for(int i = length - 1; i >= 0; i--)
    {
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        CreateBiggestHeap(a, i);
    }
    
    for(int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
#endif
    
#if 0
    int v[] = {2, 4, 3, 1};
    StraightInsertionSort sot;
//    sot.insertSort(v, 4);
    
//    sot.iSort(v, 4);
    
    ShellSort sSort;
    sSort.sort(v, 4);
    
#endif
    
    
    return 0;
}
