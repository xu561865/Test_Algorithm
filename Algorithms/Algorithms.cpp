//
//  Algorithms.cpp
//  Test_Algorithm
//
//  Created by xuyi on 25/05/2018.
//  Copyright © 2018 xuyi. All rights reserved.
//

#include <stdio.h>
#include "Algorithms.h"
#include <iostream>

void algorithm1(TreeNode * root, int sum)
{
    std::function<void(int [], int)> printPath;
    printPath = [](int arr[], int length)->void {
        for(int i = 0; i < length; ++i)
        {
            std::cout<<arr[i]<<std::endl;
        }
    };
    
    std::function<void(TreeNode * root, int sum, int path[], int top)> helper;
    helper = [helper, printPath](TreeNode * root, int sum, int path[], int top)->void {
        path[top++] = root->value;
        sum -= root->value;
        if (root->pLeft == NULL && root->pRight == NULL)
        {
            if (sum == 0) printPath(path, top);
        }
        else
        {
            if (root->pLeft != NULL) helper(root->pLeft, sum, path, top);
            if (root->pRight != NULL) helper(root->pRight, sum, path, top);
        }
        //    top --;
        //    sum -= root->value;
    };
}
