#include "IntegerIdenticalToIndex.h"
#include <cstdio>

int GetNumberSameAsIndex(const int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        return -1;
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int middle = left + ((right - left) >> 1);
        if (numbers[middle] == middle)
            return middle;
        if (numbers[middle] > middle)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}

void IntegerIdenticalToIndexTest(const char *testName, int numbers[], int length, int expected)
{
    if (GetNumberSameAsIndex(numbers, length) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s FAILED.\n", testName);
}

void IntegerIdenticalToIndexTest1()
{
    int numbers[] = {-3, -1, 1, 3, 5};
    int expected = 3;
    IntegerIdenticalToIndexTest("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}