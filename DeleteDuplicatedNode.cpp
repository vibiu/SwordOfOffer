#include "DeleteNodeInList.h"
#include <cstdio>

void DeleteDuplication(ListNode **pHead)
{
    if (pHead == nullptr || *pHead == nullptr)
        return;

    ListNode *pPreNode = nullptr;
    ListNode *pNode = *pHead;
    while (pNode != nullptr)
    {
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
            needDelete = true;

        if (!needDelete)
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }
        else
        {
            int value = pNode->m_nValue;
            ListNode *pToBeDel = pNode;
            while (pToBeDel != nullptr && pToBeDel->m_nValue == value)
            {
                pNext = pToBeDel->m_pNext;

                delete pToBeDel;

                pToBeDel = nullptr;
                pToBeDel = pNext;
            }

            if (pPreNode == nullptr)
                *pHead = pNext;
            else
                pPreNode->m_pNext = pNext;

            pNode = pNext;
        }
    }
}

void DeleteDuplicatedNodeTest(const char *testName, ListNode **pHead, int *expectedValues, int expectedLength)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    DeleteDuplication(pHead);

    int index = 0;
    ListNode *pNode = *pHead;
    while (pNode != nullptr && index < expectedLength)
    {
        if (pNode->m_nValue != expectedValues[index])
            break;

        pNode = pNode->m_pNext;
        index++;
    }

    if (pNode == nullptr && index == expectedLength)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void DeleteDuplicatedNodeTest1()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(4);
    ListNode *pNode6 = CreateListNode(4);
    ListNode *pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode *pHead = pNode1;

    int expectedValues[] = {1, 2, 5};
    DeleteDuplicatedNodeTest("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}