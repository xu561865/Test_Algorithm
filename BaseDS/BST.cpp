//
//  BST.cpp
//  Test_Algorithm
//
//  Created by xuyi on 06/03/2017.
//  Copyright © 2017 xuyi. All rights reserved.
//

#include "BST.h"
#include <iostream>

BST::BST()
{
    m_node = nullptr;
}

BST::~BST()
{
    freeTreeNode(m_node);
}

void BST::freeTreeNode(TreeNode * node)
{
    if(node)
    {
        delete node;
        
        freeTreeNode(node->pLeft);
        freeTreeNode(node->pRight);
    }
}

void BST::printBST(TreeNode * node)
{
    if(node)
    {
        std::cout<<node->value<<" ";
        
        printBST(node->pLeft);
        printBST(node->pRight);
    }
}

TreeNode * BST::generateByVector(int n[], int start, int end)
{
    if(start > end) return nullptr;
    
    int mid = start + (end - start) / 2;
    
    TreeNode * node = new TreeNode(n[mid]);
    node->pLeft = generateByVector(n, start, mid - 1);
    node->pRight = generateByVector(n, mid + 1, end);
    
//    std::cout<<node->value<<"-";
    
    return node;
}

TreeNode * BST::generateToSortedVector(TreeNode * bstTreeNode)
{
    return nullptr;
}

void helper(TreeNode *& head, TreeNode *& tail, TreeNode *root)
{
    TreeNode *lTail, *rHead;
    if (root == NULL)
    {
        head = NULL, tail = NULL;
        return;
    }
    
    helper(head, lTail, root->pLeft);
    helper(rHead, tail, root->pRight);
    
    if (lTail != NULL)
    {
        lTail->pLeft = root;
        root->pRight = lTail;
    }
    else
    {
        head = root;
    }
    
    if (rHead != NULL)
    {
        root->pRight=rHead;
        rHead->pLeft = root;
    }
    else
    {
        tail = root;
    }
}

void BST::middleSearch(TreeNode * node)
{
    if(!node)
    {
        return;
    }
    
    middleSearch(node->pLeft);
    std::cout<<node->value<<" ";
    middleSearch(node->pRight);
}

