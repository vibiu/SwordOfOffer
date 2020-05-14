#if !defined(KTH_NODE_IN_BST_H_)
#define KTH_NODE_IN_BST_H_

#include "utils/BinaryTree.h"

const BinaryTreeNode *KthNodeCore(const BinaryTreeNode *pRoot, unsigned int &k);

const BinaryTreeNode *KthNode(const BinaryTreeNode *pRoot, unsigned int k);

void KthNodeInBSTTest(const char *testName, const BinaryTreeNode *pRoot, unsigned int k, bool isNull, int expected);

void KthNodeInBSTTest1();

#endif // KTH_NODE_IN_BST_H_
