#include "NextNodeInBinaryTrees.h"
#include <cstdio>

TBinaryTreeNode *GetNext(TBinaryTreeNode *pNode)
{
    if (pNode == nullptr)
        return nullptr;

    TBinaryTreeNode *pNext = nullptr;
    if (pNode->m_pRight != nullptr)
    {
        TBinaryTreeNode *pRight = pNode->m_pRight;
        while (pRight->m_pLeft != nullptr)
            pRight = pRight->m_pLeft;

        pNext = pRight;
    }
    else if (pNode->m_pParent != nullptr)
    {
        TBinaryTreeNode *pCurrent = pNode;
        TBinaryTreeNode *pParent = pNode->m_pParent;
        while (pParent != nullptr && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }

        pNext = pParent;
    }

    return pNext;
};

TBinaryTreeNode *CreateTBinaryTreeNode(int value)
{
    TBinaryTreeNode *pNode = new TBinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pParent = nullptr;
    return pNode;
}

void TConnectTreeNodes(TBinaryTreeNode *pParent, TBinaryTreeNode *pLeft, TBinaryTreeNode *pRight)
{
    if (pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if (pLeft != nullptr)
            pLeft->m_pParent = pParent;
        if (pRight != nullptr)
            pRight->m_pParent = pParent;
    }
}

void TPrintTreeNode(TBinaryTreeNode *pNode)
{

    if (pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if (pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is null.\n");

        if (pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void TPrintTree(TBinaryTreeNode *pRoot)
{
    TPrintTreeNode(pRoot);

    if (pRoot != nullptr)
    {
        if (pRoot->m_pLeft != nullptr)
            TPrintTree(pRoot->m_pLeft);

        if (pRoot->m_pRight != nullptr)
            TPrintTree(pRoot->m_pRight);
    }
}

void TDestroyTree(TBinaryTreeNode *pRoot)
{
    if (pRoot != nullptr)
    {
        TBinaryTreeNode *pLeft = pRoot->m_pLeft;
        TBinaryTreeNode *pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        TDestroyTree(pLeft);
        TDestroyTree(pRight);
    }
}

void NextNodeInBinaryTreesTest(const char *testName, TBinaryTreeNode *pNode, TBinaryTreeNode *expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    TBinaryTreeNode *pNext = GetNext(pNode);
    if (pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void NextNodeInBinaryTreesTest1()
{
    TBinaryTreeNode *pNode8 = CreateTBinaryTreeNode(8);
    TBinaryTreeNode *pNode6 = CreateTBinaryTreeNode(6);
    TBinaryTreeNode *pNode10 = CreateTBinaryTreeNode(10);
    TBinaryTreeNode *pNode5 = CreateTBinaryTreeNode(5);
    TBinaryTreeNode *pNode7 = CreateTBinaryTreeNode(7);
    TBinaryTreeNode *pNode9 = CreateTBinaryTreeNode(9);
    TBinaryTreeNode *pNode11 = CreateTBinaryTreeNode(11);

    TConnectTreeNodes(pNode8, pNode6, pNode10);
    TConnectTreeNodes(pNode6, pNode5, pNode7);
    TConnectTreeNodes(pNode10, pNode9, pNode11);

    NextNodeInBinaryTreesTest("Test1", pNode8, pNode9);
    NextNodeInBinaryTreesTest("Test2", pNode6, pNode7);
    NextNodeInBinaryTreesTest("Test3", pNode10, pNode11);
    NextNodeInBinaryTreesTest("Test4", pNode5, pNode6);
    NextNodeInBinaryTreesTest("Test5", pNode7, pNode8);
    NextNodeInBinaryTreesTest("Test6", pNode9, pNode10);
    NextNodeInBinaryTreesTest("Test7", pNode11, nullptr);

    TDestroyTree(pNode8);
}