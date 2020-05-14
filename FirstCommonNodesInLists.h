#if !defined(FIRST_COMMON_NODES_IN_LISTS_H_)
#define FIRST_COMMON_NODES_IN_LISTS_H_

#include "utils/List.h"

unsigned int GetListLength(ListNode *pHead);

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2);

void DestroyNode(ListNode *pNode);

void FirstCommonNodesInListsTest(const char *testName, ListNode *pHead1, ListNode *pHead2, ListNode *pExpected);

void FirstCommonNodesInListsTest1();

#endif // FIRST_COMMON_NODES_IN_LISTS_H_
