#if !defined(CONVERT_BINARY_SEARCH_TREE_H_)
#define CONVERT_BINARY_SEARCH_TREE_H_

#include "utils/BinaryTree.h"

void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList);

BinaryTreeNode *Convert(BinaryTreeNode *pRootOfTree);

void PrintDoubleLinkedList(BinaryTreeNode *pHeadOfList);

void DestroyList(BinaryTreeNode *pHeadOfList);

void ConvertBinarySearchTreeTest(const char *testName, BinaryTreeNode *pRootOfTree);

void ConvertBinarySearchTreeTest1();

#endif // CONVERT_BINARY_SEARCH_TREE_H_
