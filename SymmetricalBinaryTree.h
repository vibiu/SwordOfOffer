#if !defined(SYMMETRICAL_BINARY_TREE_H_)
#define SYMMETRICAL_BINARY_TREE_H_
#include "utils/BinaryTree.h"

bool isSymmetrical(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2);

bool isSymmetrical(BinaryTreeNode *pRoot);

void SymmetricalBinaryTreeTest(const char *testName, BinaryTreeNode *pRoot, bool expected);

void SymmetricalBinaryTreeTest1();

#endif // SYMMETRICAL_BINARY_TREE_H_
