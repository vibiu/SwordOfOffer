#include "TreeDepth.h"
#include <cstdio>

int TreeDepth(const BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return 0;

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);
    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

void TreeDepthTest(const char *testName, const BinaryTreeNode *pRoot, int expected)
{
    int result = TreeDepth(pRoot);
    if (expected == result)
        printf("%s passed.\n", testName);
    else
        printf("%s FAILED.\n", testName);
}

void TreeDepthTest1()
{
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, nullptr, pNode6);
    ConnectTreeNodes(pNode5, pNode7, nullptr);

    TreeDepthTest("Test1", pNode1, 4);

    DestroyTree(pNode1);
}