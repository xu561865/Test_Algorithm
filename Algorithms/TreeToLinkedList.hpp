//
//  TreeToLinkedList.hpp
//  Test_Algorithm
//
//  Created by xuyi on 17/05/2018.
//  Copyright © 2018 xuyi. All rights reserved.
//

#ifndef TreeToLinkedList_hpp
#define TreeToLinkedList_hpp

#include <stdio.h>
#include "BST.h"

/*
 *输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。 要求不能创建任何新的结点，只调整指针的指向。
    10
    /\
    6 14
    /\/\
    4 8 12 16
    转换成双向链表
    4=6=8=10=12=14=16。
 */


class TreeToLinkedList
{
public:
    static Node * transition(Node * root);
    
private:
    static void helper(Node *& head, Node *& tail, Node *root);
};

#endif /* TreeToLinkedList_hpp */
