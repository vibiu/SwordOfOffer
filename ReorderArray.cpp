#include "ReorderArray.h"
#include <cstdio>

void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
    if (pData == nullptr || length == 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while (pBegin < pEnd)
    {
        while (pBegin < pEnd && !func(*pBegin))
            pBegin++;
        while (pBegin < pEnd && func(*pEnd))
            pEnd--;

        if (pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

bool isEven(int n)
{
    return (n & 1) == 0;
}

void ReorderOddEven_1(int *pData, unsigned int length)
{
    if (pData == nullptr || length == 0)
        return;

    int *pBegin = pData;

    int *pEnd = pData + length - 1;

    while (pBegin < pEnd)
    {
        while (pBegin < pEnd && (*pBegin & 0x01) != 0)
            pBegin++;
        while (pBegin < pEnd && (*pEnd & 0x01) == 0)
            pEnd--;

        if (pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

void ReorderOddEven_2(int *pData, unsigned int length)
{
    Reorder(pData, length, isEven);
}

void PrintArray(int numbers[], int length)
{
    if (length < 0)
        return;

    for (int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);
    printf("\n");
}

void ReorderArrayTest(const char *testName, int numbers[], int length)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    int *copy = new int[length];
    for (int i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("Test for solution 1:\n");
    PrintArray(numbers, length);
    ReorderOddEven_1(numbers, length);
    PrintArray(numbers, length);

    printf("Test for solution 2:\n");
    PrintArray(copy, length);
    ReorderOddEven_2(copy, length);
    PrintArray(copy, length);

    delete[] copy;
}

void ReorderArrayTest1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    ReorderArrayTest("Test1", numbers, sizeof(numbers) / sizeof(int));
}