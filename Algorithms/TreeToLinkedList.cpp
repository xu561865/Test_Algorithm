//
//  TreeToLinkedList.cpp
//  Test_Algorithm
//
//  Created by xuyi on 17/05/2018.
//  Copyright © 2018 xuyi. All rights reserved.
//

#include "TreeToLinkedList.hpp"


void TreeToLinkedList::helper(Node *& head, Node *& tail, Node *root)
{
    Node *lt, *rh;
    lt = rh = NULL;
    if (root == NULL)
    {
        head = NULL, tail = NULL;
        return;
    }
    helper(head, lt, root->pLeft);
    helper(rh, tail, root->pRight);
    if (lt!=NULL)
    {
        lt->pRight = root;
        root->pLeft = lt;
    }
    else
    {
        head = root;
    }
    if (rh!=NULL)
    {
        root->pRight=rh;
        rh->pLeft = root;
    }
    else
    {
        tail = root;
    }

}

/**
 * @param root The root node of the tree
 * @return The head node of the converted list.
 */
Node * TreeToLinkedList::transition(Node * root)
{
    Node * head, * tail;
    helper(head, tail, root);
    return head;
}
