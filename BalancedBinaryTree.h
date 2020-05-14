#if !defined(BALANCED_BINARY_TREE_H_)
#define BALANCED_BINARY_TREE_H_

#include "utils/BinaryTree.h"

int TreeDepth(const BinaryTreeNode *pRoot);

bool IsBalanced_Solution1(const BinaryTreeNode *pRoot);

bool IsBalanced(const BinaryTreeNode *pRoot, int *pDepth);

bool IsBalanced_Solution2(const BinaryTreeNode *pRoot);

void BalancedBinaryTreeTest(const char *testName, const BinaryTreeNode *pRoot, bool expected);

void BalancedBinaryTreeTest1();

#endif // BALANCED_BINARY_TREE_H_
