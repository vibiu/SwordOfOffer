#include "TwoNumbersWithSum.h"
#include <cstdio>

bool FindNumbersWithSum(int data[], int length, int sum, int *num1, int *num2)
{
    bool found = false;
    if (length < 1 || num1 == nullptr || num2 == nullptr)
        return found;

    int ahead = length - 1;
    int behind = 0;

    while (ahead > behind)
    {
        long long curSum = data[ahead] + data[behind];

        if (curSum == sum)
        {
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            break;
        }
        else if (curSum > sum)
            ahead--;
        else
            behind++;
    }
    return found;
}

void TwoNumbersWithSumTest(const char *testName, int data[], int length, int sum, bool expectedReturn)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    int num1, num2;
    int result = FindNumbersWithSum(data, length, sum, &num1, &num2);
    if (result == expectedReturn)
    {
        if (result)
        {
            if (num1 + num2 == sum)
                printf("Passed. \n");
            else
                printf("FAILED. \n");
        }
        else
            printf("Passed. \n");
    }
    else
        printf("FAILED. \n");
}

void TwoNumbersWithSumTest1()
{
    int data[] = {1, 2, 4, 7, 11, 15};
    TwoNumbersWithSumTest("Test1", data, sizeof(data) / sizeof(int), 15, true);
}
