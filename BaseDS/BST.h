//
//  BST.h
//  Test_Algorithm
//
//  Created by xuyi on 06/03/2017.
//  Copyright © 2017 xuyi. All rights reserved.
//

#ifndef BST_h
#define BST_h

struct Node
{
    Node(int v)
    {
        value = v;
    }
    
    int value;
    Node * pLeft;
    Node * pRight;
};

class BST
{
public:
    BST();
    ~BST();
    
    void printBST(Node *);
    void freeNode(Node *);
    
    Node * generateByVector(int [], int start, int end);
    Node * generateToSortedVector(Node *);
    void middleSearch(Node *);
private:
    Node * m_node;
};

#endif /* BST_h */
