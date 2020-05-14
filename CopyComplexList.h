#if !defined(COPY_COMPLEX_LIST_H_)
#define COPY_COMPLEX_LIST_H_
#include "utils/ComplexList.h"

void CloneNodes(ComplexListNode *pHead);
void ConnectSiblingNodes(ComplexListNode *pHead);
ComplexListNode *ReconnectNodes(ComplexListNode *pHead);

ComplexListNode *Clone(ComplexListNode *pHead);

void CopyComplexListTest(const char *testName, ComplexListNode *pHead);

void CopyComplexListTest1();
#endif // COPY_COMPLEX_LIST_H_
