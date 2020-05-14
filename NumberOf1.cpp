#include "NumberOf1.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

int NumberOf1(unsigned int n)
{
    int number = 0;
    while (n)
    {
        if (n % 10 == 1)
            number++;
        n = n / 10;
    }
    return number;
}

int NumberOf1Between1AndN_Solution1(unsigned int n)
{
    int number = 0;
    for (unsigned int i = 1; i <= n; ++i)
        number += NumberOf1(i);
    return number;
}

int NumberOf1(const char *strN)
{
    if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
        return 0;

    int first = *strN - '0';
    unsigned int length = static_cast<unsigned int>(strlen(strN));

    if (length == 1 && first == 0)
        return 0;
    if (length == 1 && first > 0)
        return 1;

    int numFirstDigit = 0;
    if (first > 1)
        numFirstDigit = PowerBase10(length - 1);
    else if (first == 1)
        numFirstDigit = atoi(strN + 1) + 1;

    int numOtherDigists = first * (length - 1) * PowerBase10(length - 2);
    int numRecursive = NumberOf1(strN + 1);

    return numFirstDigit + numOtherDigists + numRecursive;
}

int PowerBase10(unsigned int n)
{
    int result = 1;
    for (unsigned int i = 0; i < n; ++i)
        result *= 10;
    return result;
}

int NumberOf1Between1AndN_Solution2(int n)
{
    if (n <= 0)
        return 0;
    char strN[50];
    sprintf(strN, "%d", n);
    return NumberOf1(strN);
}

void NumberOf1Test(const char *testName, int n, int expected)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    if (NumberOf1Between1AndN_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if (NumberOf1Between1AndN_Solution2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void NumberOf1Test1()
{
    NumberOf1Test("Test1", 1, 1);
    NumberOf1Test("Test2", 5, 1);
    NumberOf1Test("Test3", 10, 2);
    NumberOf1Test("Test4", 55, 16);
    NumberOf1Test("Test5", 99, 20);
    NumberOf1Test("Test6", 10000, 4001);
    NumberOf1Test("Test7", 21345, 18821);
    NumberOf1Test("Test8", 0, 0);
}
