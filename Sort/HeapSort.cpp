//
//  HeapSort.cpp
//  Test_Algorithm
//
//  Created by xuyi on 06/01/2017.
//  Copyright © 2017 xuyi. All rights reserved.
//

#include "HeapSort.h"
#include <iostream>

void HeapSort::print(int a[], int n)
{
    for(int j= 0; j<n; j++)
    {
        std::cout<<a[j] <<"  ";
    }
    
    std::cout<<std::endl;
}



/**
 11.  * 已知H[s…m]除了H[s] 外均满足堆的定义
 12.  * 调整H[s],使其成为大顶堆.即将对第s个结点为根的子树筛选,
 13.  *
 14.  * @param H是待调整的堆数组
 15.  * @param s是待调整的数组元素的位置
 16.  * @param length是数组的长度
 17.  *
 18.  */
void HeapSort::HeapAdjust(int H[],int s, int length)
{
    int tmp  = H[s];
    int child = 2*s+1; //左孩子结点的位置。(i+1 为当前调整结点的右孩子结点的位置)
    while (child < length)
    {
//        int tmp  = H[s];
        if(child+1 <length && H[child]<H[child+1])
        { // 如果右孩子大于左孩子(则将 child 指向右孩子，即 child 为较大值的孩子)
            ++child ;
        }
        
        if(H[s]<H[child])
        {  // 如果较大的子结点大于父结点
                H[s] = H[child]; // 那么把较大的子结点往上移动，替换它的父结点
                s = child;       // 重新设置s ,即待调整的下一个结点的位置
                child = 2*child+1;
        }
        else
        {
            // 如果当前待调整结点大于它的左右孩子，则不需要调整，直接退出
            break;
        }
        H[s] = tmp;         // 当前待调整的结点放到比其大的孩子结点位置上
    }
    print(H,length);
}


/**
 41.  * 初始堆进行调整
 42.  * 将H[0..length-1]建成堆
 43.  * 调整完之后第一个元素是序列的最小的元素
 44.  */
void HeapSort::BuildingHeap(int H[], int length)
{
    //最后一个有孩子的节点的位置 i=  (length -1) / 2
    for (int i = (length -1) / 2 ; i >= 0; --i)
        HeapAdjust(H,i,length);
}
/**
 52.  * 堆排序算法
 53.  */
void HeapSort::sort(int H[],int length)
{
    //初始堆
    BuildingHeap(H, length);
    //从最后一个元素开始对序列进行调整
    for (int i = length - 1; i > 0; --i)
    {
        //交换堆顶元素H[0]和堆中最后一个元素
        int temp = H[i]; H[i] = H[0]; H[0] = temp;
        //每次交换堆顶元素和堆中最后一个元素之后，都要对堆进行调整
        HeapAdjust(H,0,i);
    }
}

