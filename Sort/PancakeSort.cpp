//
//  PancakeSort.cpp
//  Test_Algorithm
//
//  Created by 徐以 on 8/27/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

void printV(const vector<int> & V)
{
    printf("\n");
    for(auto i : V)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int find_max(vector<int>& V, int index)
{
    int max_index = 0;
    for(int i = 0; i <= index; i++)
    {
        if(V[max_index] < V[i])
        {
            max_index = i;
        }
    }
    
    return max_index;
}

void reverse(vector<int>& V, int index)
{
    int temp = 0;
    
    for(int i = 0; i <= index; i++)
    {
        if(i <= index / 2)
        {
            temp = V[i];
            V[i] = V[index - i];
            V[index - i] = temp;
        }
        else
        {
            return;
        }
    }
}

void pancake_sort(std::vector<int>& V)
{
    for(int i = V.size() - 1; i >= 0; i--)
    {
        int max_index = find_max(V, i);
        
        if(max_index != i)
        {
            reverse(V, max_index);
            reverse(V, i);
        }
    }
}