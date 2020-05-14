#include "CopyComplexList.h"
#include "utils/ComplexList.h"
#include <cstdio>

void CloneNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        ComplexListNode *pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = nullptr;

        pNode->m_pNext = pCloned;

        pNode = pCloned->m_pNext;
    }
}

void ConnectSiblingNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        ComplexListNode *pCloned = pNode->m_pNext;
        if (pNode->m_pSibling != nullptr)
        {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }

        pNode = pCloned->m_pNext;
    }
}

ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    ComplexListNode *pClonedHead = nullptr;
    ComplexListNode *pClonedNode = nullptr;

    if (pNode != nullptr)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while (pNode != nullptr)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;

        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pClonedHead;
}

ComplexListNode *Clone(ComplexListNode *pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

void CopyComplexListTest(const char *testName, ComplexListNode *pHead)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintComplexList(pHead);

    ComplexListNode *pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintComplexList(pClonedHead);
}

void CopyComplexListTest1()
{
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    CopyComplexListTest("Test1", pNode1);
}