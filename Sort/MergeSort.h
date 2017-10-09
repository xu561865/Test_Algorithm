//
//  MergeSort.h
//  Test_Algorithm
//
//  Created by xuyi on 09/01/2017.
//  Copyright © 2017 xuyi. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h

class MergeSort
{
public:
    MergeSort(){}
    ~MergeSort(){}
    
    void sort(int a[], int b[], int n);
    void print(int a[], int n);
    
private:
    void Merge(int *r,int *rf, int i, int m, int n);
};


#endif /* MergeSort_h */
