#if !defined(BINARY_TREE_H_)
#define BINARY_TREE_H_

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

BinaryTreeNode *CreateBinaryTreeNode(int value);

void ConnectTreeNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight);

void PrintTreeNode(const BinaryTreeNode *pNode);

void PrintTree(const BinaryTreeNode *pRoot);

void DestroyTree(BinaryTreeNode *pRoot);

#endif // BINARY_TREE_H_
