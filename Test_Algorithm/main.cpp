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
#include "QuickSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "BST.h"
#include "TreeToLinkedList.hpp"
#include "MaxSubArray.h"
#include <vector>

// test

using namespace std;


TreeNode * reverseNonrecurisve(TreeNode * head)
{
    if (head == NULL) return head;
    TreeNode * p = head;
    TreeNode * previous = NULL;
    while (p->pRight != NULL)
    {
        p->pRight = previous;
        previous = p;
        p = p->pRight;
    }
    p->pRight = previous;
    return p;
}

int main(int argc, const char * argv[]) {
//    int n[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int n[7] = {4, 6, 8, 10, 12, 14, 16};
    BST b;
    reverseNonrecurisve(b.generateByVector(n, 0, 6));

#ifdef TTLL
    int n[7] = {4, 6, 8, 10, 12, 14, 16};
    BST b;
    TreeNode * list = TreeToLinkedList::transition(b.generateByVector(n, 0, 6));
#endif
    
    return 0;
    
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
