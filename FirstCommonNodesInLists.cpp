#include "FirstCommonNodesInLists.h"
#include <cstdio>

unsigned int GetListLength(ListNode *pHead)
{
    unsigned int nLength = 0;
    ListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        ++nLength;
        pNode = pNode->m_pNext;
    }
    return nLength;
}

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    unsigned int nLength1 = GetListLength(pHead1);
    unsigned int nLength2 = GetListLength(pHead2);

    int nLengthDif = nLength1 - nLength2;

    ListNode *pListHeadLong = pHead1;
    ListNode *pListHeadShort = pHead2;
    if (nLength2 > nLength1)
    {
        pListHeadLong = pHead2;
        pListHeadShort = pHead1;
        nLengthDif = nLength2 - nLength1;
    }

    for (int i = 0; i < nLengthDif; ++i)
    {
        pListHeadLong = pListHeadLong->m_pNext;
    }

    while ((pListHeadLong != nullptr) && (pListHeadShort != nullptr) && (pListHeadShort != pListHeadLong))
    {
        pListHeadLong = pListHeadLong->m_pNext;
        pListHeadShort = pListHeadShort->m_pNext;
    }
    ListNode *pFirstCommonNode = pListHeadLong;
    return pFirstCommonNode;
}

void DestroyNode(ListNode *pNode)
{
    delete pNode;
    pNode = nullptr;
}

void FirstCommonNodesInListsTest(const char *testName, ListNode *pHead1, ListNode *pHead2, ListNode *pExpected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    ListNode *pResult = FindFirstCommonNode(pHead1, pHead2);
    if (pResult == pExpected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void FirstCommonNodesInListsTest1()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode6 = CreateListNode(6);
    ListNode *pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode6);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    FirstCommonNodesInListsTest("Test1", pNode1, pNode4, pNode6);

    DestroyNode(pNode1);
    DestroyNode(pNode2);
    DestroyNode(pNode3);
    DestroyNode(pNode4);
    DestroyNode(pNode5);
    DestroyNode(pNode6);
    DestroyNode(pNode7);
}