#include "PrintTreeFromTopToBottom.h"
#include <cstdio>
#include <deque>

void PrintFromTopToBottom(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return;

    std::deque<BinaryTreeNode *> dequeTreeNode;

    dequeTreeNode.push_back(pRoot);

    while (dequeTreeNode.size())
    {
        BinaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();

        printf("%d ", pNode->m_nValue);

        if (pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);

        if (pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
    }
}

void PrintTreeFromTopToBottomTest(const char *testName, BinaryTreeNode *pRoot)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    PrintTree(pRoot);

    printf("The nodes from top to bottom, from left to right are: \n");
    PrintFromTopToBottom(pRoot);

    printf("\n\n");
}

void PrintTreeFromTopToBottomTest1()
{
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode *pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    PrintTreeFromTopToBottomTest("Test1", pNode10);

    DestroyTree(pNode10);
}