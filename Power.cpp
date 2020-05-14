#include "Power.h"
#include <cmath>
#include <iostream>

bool g_InvalidInput = false;

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x1) == 1)
        result *= base;

    return result;
}

// double PowerWithUnsignedExponent(double base, unsigned int exponent)
// {
//     double result = 1.0;

//     for (int i = 1; i <= exponent; ++i)
//         result *= base;
//     return result;
// }

double Power(double base, int exponent)
{
    g_InvalidInput = false;
    if (equal(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
        absExponent = (unsigned int)(-exponent);

    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1.0 / result;
    return result;
}

double equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

void PowerTest(const char *testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

void PowerTest1()
{
    // 底数、指数都为正数
    PowerTest("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    PowerTest("Test2", -2, 3, -8, false);

    // 指数为负数
    PowerTest("Test3", 2, -3, 0.125, false);

    // 指数为0
    PowerTest("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    PowerTest("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    PowerTest("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    PowerTest("Test7", 0, -4, 0, true);
}
