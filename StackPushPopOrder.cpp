#include "StackPushPopOrder.h"
#include <cstdio>
#include <stack>
bool IsPopOrder(const int *pPush, const int *pPop, int nLength)
{
    bool bPossible = false;
    if (pPush != nullptr && pPop != nullptr && nLength > 0)
    {
        const int *pNextPush = pPush;
        const int *pNextPop = pPop;

        std::stack<int> stackData;

        while (pNextPop - pPop < nLength)
        {
            while (stackData.empty() || stackData.top() != *pNextPop)
            {
                if (pNextPush - pPush == nLength)
                    break;

                stackData.push(*pNextPush);

                pNextPush++;
            }

            if (stackData.top() != *pNextPop)
                break;

            stackData.pop();
            pNextPop++;
        }

        if (stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}

void StackPushPopOrderTest(const char *testName, const int *pPush, const int *pPop, int nLength, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (IsPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void StackPushPopOrderTest1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};

    StackPushPopOrderTest("Test1", push, pop, nLength, true);

    int push1[nLength] = {1, 2, 3, 4, 5};
    int pop1[nLength] = {4, 3, 5, 1, 2};

    StackPushPopOrderTest("Test3", push1, pop1, nLength, false);
}