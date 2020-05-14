#include "SerializeBinaryTrees.h"
#include <fstream>
using std::atoi;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

void Serialize(const BinaryTreeNode *pRoot, ostream &stream)
{
    if (pRoot == nullptr)
    {
        stream << "$,";
        return;
    }
    stream << pRoot->m_nValue << ",";
    Serialize(pRoot->m_pLeft, stream);
    Serialize(pRoot->m_pRight, stream);
}

bool ReadStream(istream &stream, int *number)
{
    if (stream.eof())
        return false;

    char buffer[32];
    buffer[0] = '\0';

    char ch;
    stream >> ch;
    int i = 0;
    while (!stream.eof() && ch != ',')
    {
        buffer[i++] = ch;
        stream >> ch;
    }
    bool isNumeric = false;
    if (i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumeric = true;
    }
    return isNumeric;
}

void Deserialize(BinaryTreeNode **pRoot, istream &stream)
{
    int number;
    if (ReadStream(stream, &number))
    {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->m_nValue = number;
        (*pRoot)->m_pLeft = nullptr;
        (*pRoot)->m_pRight = nullptr;

        Deserialize(&(*pRoot)->m_pLeft, stream);
        Deserialize(&(*pRoot)->m_pRight, stream);
    }
}

bool isSameTree(const BinaryTreeNode *pRoot1, const BinaryTreeNode *pRoot2)
{
    if (pRoot1 == nullptr && pRoot2 == nullptr)
        return true;

    if (pRoot1 == nullptr || pRoot2 == nullptr)
        return false;

    if (pRoot1->m_nValue != pRoot2->m_nValue)
        return false;
    return isSameTree(pRoot1->m_pLeft, pRoot2->m_pLeft) && isSameTree(pRoot1->m_pRight, pRoot2->m_pRight);
}

void SerializeBinaryTreesTest(const char *testName, const BinaryTreeNode *pRoot)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    PrintTree(pRoot);

    const char *fileName = "resources/serialize.txt";
    ofstream fileOut;
    fileOut.open(fileName);

    Serialize(pRoot, fileOut);
    fileOut.close();

    // print the serialized file
    ifstream fileIn1;
    char ch;
    fileIn1.open(fileName);
    while (!fileIn1.eof())
    {
        fileIn1 >> ch;
        cout << ch;
    }
    fileIn1.close();
    cout << endl;

    ifstream fileIn2;
    fileIn2.open(fileName);
    BinaryTreeNode *pNewRoot = nullptr;
    Deserialize(&pNewRoot, fileIn2);
    fileIn2.close();

    PrintTree(pNewRoot);

    if (isSameTree(pRoot, pNewRoot))
        printf("The deserialized tree is same as the oritinal tree.\n\n");
    else
        printf("The deserialized tree is NOT same as the oritinal tree.\n\n");

    DestroyTree(pNewRoot);
}

void SerializeBinaryTreesTest1()
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

    SerializeBinaryTreesTest("Test1", pNode8);

    DestroyTree(pNode8);
}