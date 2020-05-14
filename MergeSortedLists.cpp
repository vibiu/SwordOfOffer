#include "MergeSortedLists.h"
#include <cstdio>

ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr)
        return pHead2;
    else if (pHead2 == nullptr)
        return pHead1;

    ListNode *pMergedHead = nullptr;

    if (pHead1->m_nValue< pHead2->m_nValue)
    {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }

    return pMergedHead;
}

ListNode *MergeSortedListsTest(const char *testName, ListNode *pHead1, ListNode *pHead2)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode *pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);

    printf("\n\n");

    return pMergedHead;
}

void MergeSortedListsTest1()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode *pMergedHead = MergeSortedListsTest("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}