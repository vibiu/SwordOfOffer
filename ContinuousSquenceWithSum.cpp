#include "ContinuousSquenceWithSum.h"
#include <cstdio>

void PrintContinuousSequence(int small, int big)
{
    for (int i = small; i <= big; ++i)
        printf("%d ", i);

    printf("\n");
}

void FindContinuousSequence(int sum)
{
    if (sum < 3)
        return;
    int small = 1;
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;
    while (small < middle)
    {
        if (curSum == sum)
            PrintContinuousSequence(small, big);
        while (curSum > sum && small < middle)
        {
            curSum -= small;
            small++;

            if (curSum == sum)
                PrintContinuousSequence(small, big);
        }
        big++;
        curSum += big;
    }
}

void ContinuousSquenceWithSumTest(const char *testName, int sum)
{
    if (testName != nullptr)
        printf("%s for %d begins: \n", testName, sum);

    FindContinuousSequence(sum);
}

void ContinuousSquenceWithSumTest1()
{
    ContinuousSquenceWithSumTest("test1", 1);
    ContinuousSquenceWithSumTest("test2", 3);
    ContinuousSquenceWithSumTest("test3", 4);
    ContinuousSquenceWithSumTest("test4", 9);
    ContinuousSquenceWithSumTest("test5", 15);
    ContinuousSquenceWithSumTest("test6", 100);
}