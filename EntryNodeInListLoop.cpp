#include "EntryNodeInListLoop.h"
#include <cstdio>

ListNode *MeetingNode(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;

    ListNode *pSlow = pHead->m_pNext;
    if (pSlow == nullptr)
        return nullptr;

    ListNode *pFast = pSlow->m_pNext;

    while (pFast != nullptr && pSlow != nullptr)
    {
        if (pFast == pSlow)
            return pFast;

        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;
        if (pFast != nullptr)
        {
            pFast = pFast->m_pNext;
        }
    }
    return nullptr;
}

ListNode *EntryNodeOfLoop(ListNode *pHead)
{
    ListNode *meetingNode = MeetingNode(pHead);
    if (meetingNode == nullptr)
        return nullptr;

    int nodesInLoop = 1;
    ListNode *pNode1 = meetingNode;
    while (pNode1->m_pNext != meetingNode)
    {
        pNode1 = pNode1->m_pNext;
        ++nodesInLoop;
    }

    pNode1 = pHead;
    for (int i = 0; i < nodesInLoop; ++i)
        pNode1 = pNode1->m_pNext;

    ListNode *pNode2 = pHead;
    while (pNode1 != pNode2)
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1;
}

void EntryNodeInListLoopTest(const char *testName, ListNode *pHead, ListNode *entryNode)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void EntryNodeInListLoopTest1()
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
    ConnectListNodes(pNode5, pNode3);

    EntryNodeInListLoopTest("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}
