#include "MissingNumber.h"
#include <cstdio>

int GetMissingNumber(const int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        return -1;
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int middle = (right + left) >> 1;
        if (numbers[middle] != middle)
        {
            if (middle == 0 || numbers[middle - 1] == middle - 1)
                return middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }

    if (left == length)
        return length;

    return -1;
}

void MissingNumberTest(const char *testName, int numbers[], int length, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetMissingNumber(numbers, length);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void MissingNumberTest1()
{
    int numbers[] = {1, 2, 3, 4, 5};
    int expected = 0;
    MissingNumberTest("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}