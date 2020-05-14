#include "SquenceOfBST.h"
#include <cstdio>
bool VerifySquenceOfBST(int sequence[], int length)
{
    if (sequence == nullptr || length <= 0)
        return false;

    int root = sequence[length - 1];

    int i = 0;
    for (; i < length - 1; ++i)
    {
        if (sequence[i] > root)
            break;
    }

    int j = i;
    for (; j < length - 1; ++j)
    {
        if (sequence[j] < root)
            return false;
    }

    bool left = true;
    if (i > 0)
        left = VerifySquenceOfBST(sequence, i);

    bool right = true;
    if (i < length - 1)
        right = VerifySquenceOfBST(sequence + i, length - i - 1);

    return (left && right);
}

void SquenceOfBSTTest(const char *testName, int sequence[], int length, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

void SquenceOfBSTTest1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    SquenceOfBSTTest("Test1", data, sizeof(data) / sizeof(int), true);
}
