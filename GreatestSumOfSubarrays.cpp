#include "GreatestSumOfSubarrays.h"
#include <cstdio>

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if (pData == nullptr || nLength <= 0)
    {
        g_InvalidInput = true;
        return 0;
    }
    g_InvalidInput = false;

    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for (int i = 0; i < nLength; ++i)
    {
        if (nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        if (nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }
    return nGreatestSum;
}

void GreatestSumOfSubarraysTest(const char *testName, int *pData, int nLength, int expected, bool expectedFlag)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if (result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void GreatestSumOfSubarraysTest1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    GreatestSumOfSubarraysTest("Test1", data, sizeof(data) / sizeof(int), 18, false);
}
