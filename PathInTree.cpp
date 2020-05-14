#include "PathInTree.h"
#include <cstdio>

void FindPath(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int currentSum)
{
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);

    bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
    if (currentSum == expectedSum & isLeaf)
    {
        printf("A path is found:");
        std::vector<int>::iterator iter = path.begin();
        for (; iter != path.end(); ++iter)
            printf("%d\t", *iter);

        printf("\n");
    }

    if (pRoot->m_pLeft != nullptr)
        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    if (pRoot->m_pRight != nullptr)
        FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

    currentSum -= pRoot->m_nValue;
    path.pop_back();
}

void FindPath(BinaryTreeNode *pRoot, int expectedSum)
{
    if (pRoot == nullptr)
        return;

    std::vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}

void PathInTreeTest(const char *testName, BinaryTreeNode *pRoot, int expectedSum)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    FindPath(pRoot, expectedSum);

    printf("\n");
}

void PathInTreeTest1()
{
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    PathInTreeTest("Test1", pNode10, 22);

    DestroyTree(pNode10);
}