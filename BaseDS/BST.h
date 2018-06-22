//
//  BST.h
//  Test_Algorithm
//
//  Created by xuyi on 06/03/2017.
//  Copyright © 2017 xuyi. All rights reserved.
//

#ifndef BST_h
#define BST_h

struct TreeNode
{
    TreeNode(int v)
    {
        value = v;
    }
    
    int value;
    TreeNode * pLeft;
    TreeNode * pRight;
};

class BST
{
public:
    BST();
    ~BST();
    
    void printBST(TreeNode *);
    void freeTreeNode(TreeNode *);
    
    TreeNode * generateByVector(int [], int start, int end);
    TreeNode * generateToSortedVector(TreeNode *);
    void middleSearch(TreeNode *);
private:
    TreeNode * m_node;
};

#endif /* BST_h */
