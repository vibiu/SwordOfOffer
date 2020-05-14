#include "CommonParentInTree.h"
#include <cstdio>
#include <vector>

using std::vector;

bool GetNodePath(const TreeNode *pRoot, const TreeNode *pNode, list<const TreeNode *> &path)
{
    if (pRoot == pNode)
        return true;

    path.push_back(pRoot);

    bool found = false;

    vector<TreeNode *>::const_iterator i = pRoot->m_vChildren.begin();

    while (!found && i < pRoot->m_vChildren.end())
    {
        found = GetNodePath(*i, pNode, path);
        ++i;
    }

    if (!found)
        path.pop_back();
    return found;
}

const TreeNode *GetLastCommonNode(const list<const TreeNode *> &path1, const list<const TreeNode *> &path2)
{
    list<const TreeNode *>::const_iterator iterator1 = path1.begin();
    list<const TreeNode *>::const_iterator iterator2 = path2.begin();

    const TreeNode *pLast = nullptr;

    while (iterator1 != path1.end() && iterator2 != path2.end())
    {
        if (*iterator1 == *iterator2)
            pLast = *iterator1;

        iterator1++;
        iterator2++;
    }
    return pLast;
}

const TreeNode *GetLastCommonParent(const TreeNode *pRoot, const TreeNode *pNode1, const TreeNode *pNode2)
{
    if (pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
        return nullptr;

    list<const TreeNode *> path1;

    GetNodePath(pRoot, pNode1, path1);

    list<const TreeNode *> path2;

    GetNodePath(pRoot, pNode2, path2);

    return GetLastCommonNode(path1, path2);
}

void CommonParentInTreeTest(const char *testName, const TreeNode *pRoot, const TreeNode *pNode1, const TreeNode *pNode2,
                            TreeNode *pExpected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    const TreeNode *pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

    if ((pExpected == nullptr && pResult == nullptr) ||
        (pExpected != nullptr && pResult != nullptr && pResult->m_nValue == pExpected->m_nValue))
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void CommonParentInTreeTest1()
{
    TreeNode *pNode1 = CreateTreeNode(1);
    TreeNode *pNode2 = CreateTreeNode(2);
    TreeNode *pNode3 = CreateTreeNode(3);
    TreeNode *pNode4 = CreateTreeNode(4);
    TreeNode *pNode5 = CreateTreeNode(5);
    TreeNode *pNode6 = CreateTreeNode(6);
    TreeNode *pNode7 = CreateTreeNode(7);
    TreeNode *pNode8 = CreateTreeNode(8);
    TreeNode *pNode9 = CreateTreeNode(9);
    TreeNode *pNode10 = CreateTreeNode(10);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3);

    ConnectTreeNodes(pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5);

    ConnectTreeNodes(pNode4, pNode6);
    ConnectTreeNodes(pNode4, pNode7);

    ConnectTreeNodes(pNode5, pNode8);
    ConnectTreeNodes(pNode5, pNode9);
    ConnectTreeNodes(pNode5, pNode10);

    CommonParentInTreeTest("Test1", pNode1, pNode6, pNode8, pNode2);
}