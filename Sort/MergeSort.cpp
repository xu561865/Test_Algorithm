//
//  MergeSort.cpp
//  Test_Algorithm
//
//  Created by xuyi on 09/01/2017.
//  Copyright © 2017 xuyi. All rights reserved.
//

#include "MergeSort.h"
#include <iostream>
using namespace std;

void MergeSort::print(int a[], int n)
{
    for(int j= 0; j<n; j++)
    {
        cout<<a[j] <<"  ";
    }
    cout<<endl;
}

//将r[i…m]和r[m +1 …n]归并到辅助数组rf[i…n]
void MergeSort::Merge(int *r,int *rf, int i, int m, int n)
{
    int j, k;
    for(k = i, j = m + 1; i <= m && j <= n; ++k)
    {
        if(r[j] < r[i])
        {
            rf[k] = r[j++];
        }
        else
        {
            rf[k] = r[i++];
        }
    }
    
    while(i <= m)
    {
        rf[k++] = r[i++];
    }
    
    while(j <= n)
    {
        rf[k++] = r[j++];
    }
    
    print(rf,n+1);
}

void MergeSort::sort(int *r, int *rf, int length)
{
    int len = 1;
    int *q = r ;
    int *tmp ;
    while(len < length)
    {
        int s = len;
        len = 2 * s ;
        int i = 0;
        while(i + len < length)
        {
            Merge(q, rf, i, i + s - 1, i + len - 1 ); //对等长的两个子表合并
            i = i + len;
        }
        
        if(i + s < length)
        {
            Merge(q, rf,  i, i + s - 1, length - 1); //对不等长的两个子表合并
        }
        
        tmp = q; q = rf; rf = tmp; //交换q,rf，以保证下一趟归并时，仍从q 归并到rf
    }
}
