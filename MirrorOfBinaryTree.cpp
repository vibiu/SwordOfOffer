#include "MirrorOfBinaryTree.h"
#include <cstdio>
#include <stack>

void MirrorRecursively(BinaryTreeNode *pNode)
{
    if ((pNode == nullptr) || (pNode->m_pLeft == nullptr))
        return;

    BinaryTreeNode *pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    if (pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);

    if (pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}

void MirrorIteratively(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return;

    std::stack<BinaryTreeNode *> stackTreeNode;
    stackTreeNode.push(pRoot);

    while (stackTreeNode.size() > 0)
    {
        BinaryTreeNode *pNode = stackTreeNode.top();
        stackTreeNode.pop();

        BinaryTreeNode *pTemp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = pTemp;

        if (pNode->m_pLeft)
            stackTreeNode.push(pNode->m_pLeft);
        if (pNode->m_pRight)
            stackTreeNode.push(pNode->m_pRight);
    }
}

void MirrorOfBinaryTreeTest()
{
    printf("=====Test1 starts:=====\n");
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    PrintTree(pNode8);

    printf("=====Test1: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test1: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}
