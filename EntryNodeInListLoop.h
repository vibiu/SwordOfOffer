#if !defined(ENTRY_NODE_IN_LIST_LOOP_H_)
#define ENTRY_NODE_IN_LIST_LOOP_H_
#include "utils/List.h"

ListNode *MeetingNode(ListNode *pHead);

ListNode *EntryNodeOfLoop(ListNode *pHead);

void EntryNodeInListLoopTest(const char *testName, ListNode *pHead, ListNode *entryNode);

void EntryNodeInListLoopTest1();

#endif // ENTRY_NODE_IN_LIST_LOOP_H_
