#include "BalancedBinaryTree.h"
#include <cstdio>

int TreeDepth(const BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return 0;
    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);
    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

bool IsBalanced_Solution1(const BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return true;

    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);
    int diff = left - right;
    if (diff > 1 || diff < -1)
        return false;

    return IsBalanced_Solution1(pRoot->m_pLeft) && IsBalanced_Solution1(pRoot->m_pRight);
}

bool IsBalanced(const BinaryTreeNode *pRoot, int *pDepth)
{
    if (pRoot == nullptr)
    {
        *pDepth = 0;
        return true;
    }
    int left, right;
    if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right))
    {
        int diff = left - right;
        if (diff <= 1 && diff >= -1)
        {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}

bool IsBalanced_Solution2(const BinaryTreeNode *pRoot)
{
    int depth = 0;
    return IsBalanced(pRoot, &depth);
}

void BalancedBinaryTreeTest(const char *testName, const BinaryTreeNode *pRoot, bool expected)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("Solution1 begins: ");
    if (IsBalanced_Solution1(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Solution2 begins: ");
    if (IsBalanced_Solution2(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void BalancedBinaryTreeTest1()
{
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, pNode6, pNode7);

    BalancedBinaryTreeTest("Test1", pNode1, true);

    DestroyTree(pNode1);
}