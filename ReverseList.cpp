#include "ReverseList.h"
#include <cstdio>

ListNode *ReverseList(ListNode *pHead)
{
    ListNode *pReversedHead = nullptr;
    ListNode *pNode = pHead;
    ListNode *pPrev = nullptr;

    while (pNode != nullptr)
    {
        ListNode *pNext = pNode->m_pNext;

        if (pNext == nullptr)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;

        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}

ListNode *ReverseListTest(ListNode *pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode *pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

void ReverseListTest1()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode *pReversedHead = ReverseListTest(pNode1);

    DestroyList(pReversedHead);
}