#include "SubstructrueInTree.h"
#include <cstdio>

bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    bool result = false;
    if (pRoot1 != nullptr && pRoot2 != nullptr)
    {
        if (Equal(pRoot1->m_nValue, pRoot2->m_nValue))
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        if (!result)
            result = HasSubtree(pRoot1->m_pLeft, pRoot2);
        if (!result)
            result = HasSubtree(pRoot2->m_pRight, pRoot2);
    }

    return result;
}

bool DoesTree1HaveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    if (pRoot2 == nullptr)
        return true;

    if (pRoot1 == nullptr)
        return false;
    if (!Equal(pRoot1->m_nValue, pRoot2->m_nValue))
        return false;

    return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
           DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool Equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.00000001))
        return true;
    else
        return false;
}

void SubstructrueInTreeTest(const char *testName, BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2, bool expected)
{
    if (HasSubtree(pRoot1, pRoot2) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s failed.\n", testName);
}

void SubstructrueInTreeTest1()
{
    BinaryTreeNode *pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeA5 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode *pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    SubstructrueInTreeTest("Test1", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}