#if !defined(COMPLEX_LIST_H_)
#define COMPLEX_LIST_H_

struct ComplexListNode
{
    int m_nValue;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
};

ComplexListNode *CreateNode(int nValue);

void BuildNodes(ComplexListNode *pNode, ComplexListNode *pNext, ComplexListNode *pSibling);

void PrintComplexList(ComplexListNode *pHead);

#endif // COMPLEX_LIST_H_
