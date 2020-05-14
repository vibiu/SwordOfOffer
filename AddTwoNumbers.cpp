#include "AddTwoNumbers.h"
#include <cstdio>

int Add(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    } while (num2 != 0);
    return num1;
}

void AddTwoNumbersTest(int num1, int num2, int expected)
{
    int result = Add(num1, num2);
    if (result == expected)
        printf("%d + %d is %d. Passed\n", num1, num2, result);
    else
        printf("%d + %d is %d. FAILED\n", num1, num2, result);
}

void AddTwoNumbersTest1()
{
    AddTwoNumbersTest(1, 2, 3);
    AddTwoNumbersTest(111, 899, 1010);

    AddTwoNumbersTest(-1, 2, 1);
    AddTwoNumbersTest(1, -2, -1);

    AddTwoNumbersTest(3, 0, 3);
    AddTwoNumbersTest(0, -4, -4);

    AddTwoNumbersTest(-2, -8, -10);
}
