#include "MoreThanHalfNumber.h"
#include <cstdio>

bool g_bInputInvalid = false;

bool CheckInvalidArray(int *numbers, int length)
{
    g_bInputInvalid = false;
    if (numbers == nullptr && length <= 0)
        g_bInputInvalid = true;
    return g_bInputInvalid;
}

bool checkMoreThanHalf(int *numbers, int length, int number)
{
    int times = 0;
    for (int i = 0; i < length; ++i)
    {
        if (numbers[i] == number)
            times++;
    }
    bool isMoreThanHalf = true;
    if (times * 2 <= length)
    {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }
    return isMoreThanHalf;
}

int MoreThanHalfNum_Solution1(int *numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
        return 0;

    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(numbers, length, start, end);
    while (index != middle)
    {
        if (index > middle)
        {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }
    int result = numbers[middle];
    if (!checkMoreThanHalf(numbers, length, result))
        result = 0;
    return result;
}

int MoreThanHalfNum_Solution2(int *numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
        return 0;

    int result = numbers[0];
    int times = 1;

    for (int i = 1; i < length; ++i)
    {
        if (times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if (numbers[i] == result)
            times++;
        else
            times--;
    }
    if (!checkMoreThanHalf(numbers, length, result))
        result = 0;
    return result;
}

void MoreThanHalfNumberTest(const char *testName, int *numbers, int length, int expectedValue, bool expectedFlag)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    int *copy = new int[length];
    for (int i = 0; i < length; ++i)
        copy[i] = numbers[i];

    printf("Test for solution1: ");
    int result = MoreThanHalfNum_Solution1(numbers, length);
    if (result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test for solution2: ");
    result = MoreThanHalfNum_Solution2(copy, length);
    if (result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    delete[] copy;
}

void MoreThanHalfNumberTest1()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    MoreThanHalfNumberTest("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}