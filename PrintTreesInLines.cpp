#include "PrintTreesInLines.h"
#include <cstdio>
#include <queue>

void PrintTreeInLines(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return;

    std::queue<BinaryTreeNode *> nodes;
    nodes.push(pRoot);
    int nextLevel = 0;
    int toBePrinted = 1;
    while (!nodes.empty())
    {
        BinaryTreeNode *pNode = nodes.front();
        printf("%d ", pNode->m_nValue);

        if (pNode->m_pLeft != nullptr)
        {
            nodes.push(pNode->m_pLeft);
            ++nextLevel;
        }
        if (pNode->m_pRight != nullptr)
        {
            nodes.push(pNode->m_pRight);
            ++nextLevel;
        }

        nodes.pop();
        --toBePrinted;

        if (toBePrinted == 0)
        {
            printf("\n");
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }
}

void PrintTreesInLinesTest()
{
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

    printf("====Test1 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("6 10 \n");
    printf("5 7 9 11 \n\n");

    printf("Actual Result is: \n");
    PrintTreeInLines(pNode8);
    printf("\n");

    DestroyTree(pNode8);
}
