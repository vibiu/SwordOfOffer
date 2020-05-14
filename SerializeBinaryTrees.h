#if !defined(SERIALIZE_BINARY_TREES_H_)
#define SERIALIZE_BINARY_TREES_H_
#include "utils/BinaryTree.h"
#include <iostream>
using std::istream;
using std::ostream;

void Serialize(const BinaryTreeNode *pRoot, ostream &stream);

bool ReadStream(istream &stream, int *number);

void Deserialize(BinaryTreeNode **pRoot, istream &stream);

bool isSameTree(const BinaryTreeNode *pRoot1, const BinaryTreeNode *pRoot2);

void SerializeBinaryTreesTest(const char *testName, const BinaryTreeNode *pRoot);

void SerializeBinaryTreesTest1();

#endif // SERIALIZE_BINARY_TREES_H_
