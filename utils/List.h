#if !defined(LIST_NODE_H_)
#define LIST_NODE_H_
struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

ListNode *CreateListNode(int value);
void ConnectListNodes(ListNode *pCurrent, ListNode *pNext);
void PrintListNode(ListNode *pNode);
void PrintList(ListNode *pHead);
void DestroyList(ListNode *pHead);
void AddToTail(ListNode **pHead, int value);
void RemoveNode(ListNode **pHead, int value);

#endif // LIST_NODE_H_
