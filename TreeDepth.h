#if !defined(TREE_DEPTH_H_)
#define TREE_DEPTH_H_

#include "utils/BinaryTree.h"

int TreeDepth(const BinaryTreeNode *pRoot);

void TreeDepthTest(const char *testName, const BinaryTreeNode *pRoot, int expected);

void TreeDepthTest1();

#endif // TREE_DEPTH_H_