#include "CuttingRope.h"
#include <cmath>
#include <iostream>

int maxProductAfterCutting_solution1(int length)
{
    if (length < 2)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3)
        return 2;

    int *products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    int max = 0;
    for (int i = 4; i <= length; ++i)
    {
        max = 0;
        for (int j = 1; j <= i / 2; ++j)
        {
            int product = products[j] * products[i - j];
            if (max < product)
                max = product;

            products[i] = max;
        }
    }
    max = products[length];
    delete[] products;
    return max;
}

int maxProductAfterCutting_solution2(int length)
{
    if (length < 2)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3)
        return 2;
    int timesOf3 = length / 3;

    if (length - timesOf3 * 3 == 1)
        timesOf3 -= 1;
    int timesOf2 = (length - timesOf3 * 3) / 2;
    return (int)(pow(3, timesOf3)) * (int)(pow(2, timesOf2));
}

void CuttingRopeTest(const char *testName, int length, int expected)
{
    int result1 = maxProductAfterCutting_solution1(length);
    if (result1 == expected)
        std::cout << "Solution1 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

    int result2 = maxProductAfterCutting_solution2(length);
    if (result2 == expected)
        std::cout << "Solution2 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void CuttingRopeTest1()
{
    int length = 1;
    int expected = 0;
    CuttingRopeTest("test1", length, expected);
    length = 10;
    expected = 36;
    CuttingRopeTest("test10", length, expected);
}
