#if !defined(DELETE_DUPLICATED_NODE_H_)
#define DELETE_DUPLICATED_NODE_H_
#include "utils/List.h"

void DeleteDuplication(ListNode **pHead);

void DeleteDuplicatedNodeTest(const char *testName, ListNode **pHead, int *expectedValues, int expectedLength);

void DeleteDuplicatedNodeTest1();
#endif // DELETE_DUPLICATED_NODE_H_
