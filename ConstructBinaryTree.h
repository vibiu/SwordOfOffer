#if !defined(CONSTRUCT_BINARYTREE_H_)
#define CONSTRUCT_BINARYTREE_H_
#include "utils/BinaryTree.h"

BinaryTreeNode *ConstructCore(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder);

BinaryTreeNode *Construct(int *preorder, int *inorder, int length);

void ConstructBinaryTreeTest(const char *testName, int *preorder, int *inorder, int length);

void ConstructBinaryTreeTest1();

#endif // CONSTRUCT_BINARYTREE_H_
