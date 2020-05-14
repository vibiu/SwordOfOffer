#include "KthNodeInBST.h"
#include <cstdio>

const BinaryTreeNode *KthNodeCore(const BinaryTreeNode *pRoot, unsigned int &k)
{
    const BinaryTreeNode *target = nullptr;
    if (pRoot->m_pLeft != nullptr)
        target = KthNodeCore(pRoot->m_pLeft, k);
    if (target == nullptr)
    {
        if (k == 1)
            target = pRoot;
        k--;
    }
    if (target == nullptr && pRoot->m_pRight != nullptr)
        target = KthNodeCore(pRoot->m_pRight, k);

    return target;
}

const BinaryTreeNode *KthNode(const BinaryTreeNode *pRoot, unsigned int k)
{
    if (pRoot == nullptr || k == 0)
        return nullptr;
    return KthNodeCore(pRoot, k);
}

void KthNodeInBSTTest(const char *testName, const BinaryTreeNode *pRoot, unsigned int k, bool isNull, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    const BinaryTreeNode *pTarget = KthNode(pRoot, k);
    if ((isNull && pTarget == nullptr) || (!isNull && pTarget->m_nValue == expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void KthNodeInBSTTest1()
{
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    KthNodeInBSTTest("TestA0", pNode8, 0, true, -1);
    KthNodeInBSTTest("TestA1", pNode8, 1, false, 5);
    KthNodeInBSTTest("TestA2", pNode8, 2, false, 6);
    KthNodeInBSTTest("TestA3", pNode8, 3, false, 7);
    KthNodeInBSTTest("TestA4", pNode8, 4, false, 8);
    KthNodeInBSTTest("TestA5", pNode8, 5, false, 9);
    KthNodeInBSTTest("TestA6", pNode8, 6, false, 10);
    KthNodeInBSTTest("TestA7", pNode8, 7, false, 11);
    KthNodeInBSTTest("TestA8", pNode8, 8, true, -1);

    DestroyTree(pNode8);

    printf("\n\n");
}