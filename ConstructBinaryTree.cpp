#include "ConstructBinaryTree.h"
#include <cstdio>
#include <stdexcept>

BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *endInorder)
            return root;
        else
            throw std::runtime_error("Invalid input.");
    }

    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;

    if (rootInorder == endInorder && *rootInorder != rootValue)
    {
        throw std::runtime_error("Invalid input.");
    }
    int leftLength = rootInorder - startInorder;
    int *leftPreorderdEnd = startPreorder + leftLength;

    if (leftLength > 0)
    {
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderdEnd, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder)
    {
        root->m_pRight = ConstructCore(leftPreorderdEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return root;
}

BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{
    if (preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

void ConstructBinaryTreeTest(const char *testName, int *preorder, int *inorder, int length)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for (int i = 0; i < length; ++i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for (int i = 0; i < length; ++i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode *root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch (std::runtime_error &exception)
    {
        printf("Invalid Input.\n");
    }
}

void ConstructBinaryTreeTest1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    ConstructBinaryTreeTest("Test1", preorder, inorder, length);
}