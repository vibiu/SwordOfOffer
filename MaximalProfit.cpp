#include "MaximalProfit.h"
#include <cstdio>

int MaxDiff(const int *numbers, unsigned length)
{
    if (numbers == nullptr && length < 2)
        return 0;

    int min = numbers[0];
    int maxDiff = numbers[1] - min;
    for (int i = 2; i < length; ++i)
    {
        if (numbers[i - 1] < min)
            min = numbers[i - 1];

        int currentDiff = numbers[i] - min;
        if (currentDiff > maxDiff)
            maxDiff = currentDiff;
    }

    return maxDiff;
}

void MaximalProfitTest(const char *testName, const int *numbers, unsigned int length, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (MaxDiff(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void MaximalProfitTest1()
{
    int numbers[] = {4, 1, 3, 2, 5};
    MaximalProfitTest("Test1", numbers, sizeof(numbers) / sizeof(int), 4);
}
