//
//  HeapSort.h
//  Test_Algorithm
//
//  Created by xuyi on 06/01/2017.
//  Copyright © 2017 xuyi. All rights reserved.
//

#ifndef HeapSort_h
#define HeapSort_h

#include <stdio.h>

class HeapSort
{
public:
    HeapSort(){}
    ~HeapSort(){}
    
    void sort(int a[], int n);
    void print(int a[], int n);
    
private:
    void HeapAdjust(int H[],int s, int length);
    void BuildingHeap(int H[], int length);
};

#endif /* HeapSort_h */
