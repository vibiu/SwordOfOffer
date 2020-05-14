#include "DigitsInSequence.h"

// #include <algorithm>
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

int countOfIntegers(int digits)
{
    if (digits == 1)
        return 10;
    int count = (int)std::pow(10, digits - 1);
    return 9 * count;
}

int digitAtIndex(int index, int digits)
{
    int number = beginNumber(digits) + index / digits;
    int indexFromRight = digits - index % digits;
    for (int i = 1; i < indexFromRight; ++i)
        number /= 10;
    return number % 10;
}

int beginNumber(int digits)
{
    if (digits == 1)
        return 0;
    return (int)std::pow(10, digits - 1);
}

int digitAtIndex(int index)
{
    if (index < 0)
        return -1;

    int digits = 1;
    while (true)
    {
        int numbers = countOfIntegers(digits);
        if (index < numbers * digits)
            return digitAtIndex(index, digits);
        index -= digits * numbers;
        digits++;
    }
    return -1;
}

void DigitsInSequenceTest(const char *testName, int inputIndex, int expectedOutput)
{
    if (digitAtIndex(inputIndex) == expectedOutput)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED." << endl;
}

void DigitsInSequenceTest1()
{
    DigitsInSequenceTest("Test1", 0, 0);
    DigitsInSequenceTest("Test2", 1, 1);
    DigitsInSequenceTest("Test3", 9, 9);
    DigitsInSequenceTest("Test4", 10, 1);
    DigitsInSequenceTest("Test5", 189, 9);  // 数字99的最后一位，9
    DigitsInSequenceTest("Test6", 190, 1);  // 数字100的第一位，1
    DigitsInSequenceTest("Test7", 1000, 3); // 数字370的第一位，3
    DigitsInSequenceTest("Test8", 1001, 7); // 数字370的第二位，7
    DigitsInSequenceTest("Test9", 1002, 0); // 数字370的第三位，0
}