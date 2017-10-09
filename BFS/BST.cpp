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
    freeNode(m_node);
}

void BST::freeNode(Node * node)
{
    if(node)
    {
        delete node;
        
        freeNode(node->pLeft);
        freeNode(node->pRight);
    }
}

void BST::printBST(Node * node)
{
    if(node)
    {
        std::cout<<node->value<<" ";
        
        printBST(node->pLeft);
        printBST(node->pRight);
    }
}

Node * BST::generateByVector(int n[], int start, int end)
{
    if(start > end) return nullptr;
    
    int mid = start + (end - start) / 2;
    
    Node * node = new Node(n[mid]);
    node->pLeft = generateByVector(n, start, mid - 1);
    node->pRight = generateByVector(n, mid + 1, end);
    
//    std::cout<<node->value<<"-";
    
    return node;
}

Node * BST::generateToSortedVector(Node * bstNode)
{
    return nullptr;
}

void helper(Node *& head, Node *& tail, Node *root)
{
    Node *lTail, *rHead;
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

void BST::middleSearch(Node * node)
{
    if(!node)
    {
        return;
    }
    
    middleSearch(node->pLeft);
    std::cout<<node->value<<" ";
    middleSearch(node->pRight);
}

