#include "ContinousCard.h"
#include <cstdio>
#include <cstdlib>

int Compare(const void *arg1, const void *arg2)
{
    return *(int *)arg1 - *(int *)arg2;
}

bool IsContinuous(int *numbers, int length)
{
    if (numbers == nullptr || length < 1)
        return false;
    qsort(numbers, length, sizeof(int), Compare);

    int numberOfZero = 0;
    int numberOfGap = 0;

    for (int i = 0; i < length && numbers[i] == 0; ++i)
        ++numberOfZero;

    int small = numberOfZero;
    int big = small + 1;
    while (big < length)
    {
        if (numbers[small] == numbers[big])
            return false;

        numberOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        ++big;
    }
    return (numberOfGap > numberOfZero) ? false : true;
}

void ContinousCardTest(const char *testName, int *numbers, int length, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (IsContinuous(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void ContinousCardTest1()
{
    int numbers[] = {1, 3, 2, 5, 4};
    ContinousCardTest("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}
