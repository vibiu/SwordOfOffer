#include "KthNodeFromEnd.h"
#include <cstdio>

ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
{
    if (pListHead == nullptr || k == 0)
        return nullptr;

    ListNode *pAhead = pListHead;
    ListNode *pBehind = nullptr;

    for (unsigned int i = 0; i < k - 1; ++i)
    {
        if (pAhead->m_pNext != nullptr)
            pAhead = pAhead->m_pNext;
        else
            return nullptr;
    }
    pBehind = pListHead;
    while (pAhead->m_pNext != nullptr)
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}

void KthNodeFromEndTest()
{
    printf("=====Test1 starts:=====\n");
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode *pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);

    DestroyList(pNode1);
}