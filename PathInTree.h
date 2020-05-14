#if !defined(PATH_IN_TREE_H_)
#define PATH_IN_TREE_H_

#include "utils/BinaryTree.h"
#include <vector>

void FindPath(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int currentSum);

void FindPath(BinaryTreeNode *pRoot, int expectedSum);

void PathInTreeTest(const char *testName, BinaryTreeNode *pRoot, int expectedSum);

void PathInTreeTest1();
#endif // PATH_IN_TREE_H_
