//
//  TreeToLinkedList.cpp
//  Test_Algorithm
//
//  Created by xuyi on 17/05/2018.
//  Copyright © 2018 xuyi. All rights reserved.
//

#include "TreeToLinkedList.hpp"


void TreeToLinkedList::helper(TreeNode *& head, TreeNode *& tail, TreeNode *root)
{
    TreeNode * lt = NULL;
    TreeNode * rh = NULL;
    
    if (root == NULL)
    {
        return;
    }
    
    helper(head, lt, root->pLeft);
    helper(rh, tail, root->pRight);
    
    if (lt == NULL)
    {
        head = root;
    }
    else
    {
        lt->pRight = root;
        root->pLeft = lt;
    }
    
    if (rh == NULL)
    {
        tail = root;
    }
    else
    {
        root->pRight = rh;
        rh->pLeft = root;
    }
}

/**
 * @param root The root node of the tree
 * @return The head node of the converted list.
 */
TreeNode * TreeToLinkedList::transition(TreeNode * root)
{
    TreeNode * head = NULL;
    TreeNode * tail = NULL;
    helper(head, tail, root);
    return head;
}
