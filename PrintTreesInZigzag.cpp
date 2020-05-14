#include "PrintTressInZigzag.h"
#include <cstdio>
#include <stack>

void PrintTreeInZigzag(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return;

    std::stack<BinaryTreeNode *> levels[2];
    int current = 0;
    int next = 1;

    levels[current].push(pRoot);
    while (!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode *pNode = levels[current].top();
        levels[current].pop();

        printf("%d ", pNode->m_nValue);

        if (current == 0)
        {
            if (pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
            if (pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
        }
        else
        {
            if (pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
            if (pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
        }

        if (levels[current].empty())
        {
            printf("\n");
            current = 1 - current;
            next = 1 - next;
        }
    }
}

void PrintTreesInZigzagTest()
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
    printf("10 6 \n");
    printf("5 7 9 11 \n\n");

    printf("Actual Result is: \n");
    PrintTreeInZigzag(pNode8);
    printf("\n");

    DestroyTree(pNode8);
}