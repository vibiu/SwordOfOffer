#include "SymmetricalBinaryTree.h"
#include <cstdio>

bool isSymmetrical(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    if (pRoot1 == nullptr && pRoot2 == nullptr)
        return true;
    if (pRoot1 == nullptr || pRoot2 == nullptr)
        return false;
    if (pRoot1->m_nValue != pRoot2->m_nValue)
        return false;

    return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

bool isSymmetrical(BinaryTreeNode *pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}

void SymmetricalBinaryTreeTest(const char *testName, BinaryTreeNode *pRoot, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (isSymmetrical(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void SymmetricalBinaryTreeTest1()
{
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode72 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode52 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, pNode52);

    SymmetricalBinaryTreeTest("Test1", pNode8, true);

    DestroyTree(pNode8);
}