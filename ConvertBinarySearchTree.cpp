#include "ConvertBinarySearchTree.h"
#include <cstdio>

void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList)
{
    if (pNode == nullptr)
        return;

    BinaryTreeNode *pCurrent = pNode;

    if (pCurrent->m_pLeft != nullptr)
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList != nullptr)
        (*pLastNodeInList)->m_pRight = pCurrent;

    *pLastNodeInList = pCurrent;
    
    if (pCurrent->m_pRight != nullptr)
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}

BinaryTreeNode *Convert(BinaryTreeNode *pRootOfTree)
{
    BinaryTreeNode *pLastNodeInList = nullptr;
    ConvertNode(pRootOfTree, &pLastNodeInList);

    BinaryTreeNode *pHeadOfList = pLastNodeInList;
    while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
        pHeadOfList = pHeadOfList->m_pLeft;

    return pHeadOfList;
}

void PrintDoubleLinkedList(BinaryTreeNode *pHeadOfList)
{
    BinaryTreeNode *pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while (pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);

        if (pNode->m_pRight == nullptr)
            break;
        pNode = pNode->m_pRight;
    }

    printf("\nThe nodes from right to left are:\n");
    while (pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);

        if (pNode->m_pLeft == nullptr)
            break;
        pNode = pNode->m_pLeft;
    }

    printf("\n");
}

void DestroyList(BinaryTreeNode *pHeadOfList)
{
    BinaryTreeNode *pNode = pHeadOfList;
    while (pNode != nullptr)
    {
        BinaryTreeNode *pNext = pNode->m_pRight;
        delete pNode;
        pNode = pNext;
    }
}

void ConvertBinarySearchTreeTest(const char *testName, BinaryTreeNode *pRootOfTree)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    PrintTree(pRootOfTree);

    BinaryTreeNode *pHeadOfList = Convert(pRootOfTree);

    PrintDoubleLinkedList(pHeadOfList);
}

void ConvertBinarySearchTreeTest1()
{
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode *pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    ConvertBinarySearchTreeTest("Test1", pNode10);

    DestroyList(pNode4);
}