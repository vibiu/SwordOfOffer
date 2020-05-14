#if !defined(NEXT_NODE_IN_BINARY_TREES_H_)
#define NEXT_NODE_IN_BINARY_TREES_H_
struct TBinaryTreeNode
{
    int m_nValue;
    TBinaryTreeNode *m_pLeft;
    TBinaryTreeNode *m_pRight;
    TBinaryTreeNode *m_pParent;
};

TBinaryTreeNode *GetNext(TBinaryTreeNode *pNode);

TBinaryTreeNode *CreateTBinaryTreeNode(int value);

void TConnectTreeNodes(TBinaryTreeNode *parent, TBinaryTreeNode *pLeft, TBinaryTreeNode *pRight);

void TPrintTreeNode(TBinaryTreeNode *pNode);

void TPrintTree(TBinaryTreeNode *pRoot);

void TDestroyTree(TBinaryTreeNode *pRoot);

void NextNodeInBinaryTreesTest(const char *testName, TBinaryTreeNode *pNode, TBinaryTreeNode *expected);

void NextNodeInBinaryTreesTest1();

#endif // NEXT_NODE_IN_BINARY_TREES_H_
