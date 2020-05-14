#if !defined(SUBSTRUCTURE_IN_TREE_H_)
#define SUBSTRUCTURE_IN_TREE_H_
#include "utils/BinaryTree.h"

bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2);

bool DoesTree1HaveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2);

bool Equal(double num1, double num2);

void SubstructrueInTreeTest(const char *testName, BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2, bool expected);

void SubstructrueInTreeTest1();

#endif // SUBSTRUCTURE_IN_TREE_H_
