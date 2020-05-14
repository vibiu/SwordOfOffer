#include "MaxValueOfGifts.h"

#include <iostream>

int getMaxValue_solution1(const int *values, int rows, int cols)
{
    if (values == nullptr || rows <= 0 || cols <= 0)
        return 0;

    int **maxValues = new int *[rows];
    for (int i = 0; i < rows; ++i)
        maxValues[i] = new int[cols];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int left = 0;
            int up = 0;

            if (i > 0)
                up = maxValues[i - 1][j];

            if (j > 0)
                left = maxValues[i][j - 1];
            int maxOne = left > up ? left : up;
            maxValues[i][j] = maxOne + values[i * cols + j];
        }
    }

    int maxValue = maxValues[rows - 1][cols - 1];

    for (int i = 0; i < rows; ++i)
        delete[] maxValues[i];
    delete[] maxValues;

    return maxValue;
}

int getMaxValue_solution2(const int *values, int rows, int cols)
{
    if (values == nullptr || rows <= 0 || cols <= 0)
        return 0;
    int *maxValues = new int[cols];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int left = 0;
            int up = 0;
            if (i > 0)
                up = maxValues[j];
            if (j > 0)
                left = maxValues[j - 1];

            int maxOne = left > up ? left : up;

            maxValues[j] = maxOne + values[i * cols + j];
        }
    }

    int maxValue = maxValues[cols - 1];
    delete[] maxValues;
    return maxValue;
}

void MaxValueOfGiftsTest(const char *testName, const int *values, int rows, int cols, int expected)
{
    if (getMaxValue_solution1(values, rows, cols) == expected)
        std::cout << testName << ": solution1 passed." << std::endl;
    else
        std::cout << testName << ": solution1 FAILED." << std::endl;

    if (getMaxValue_solution2(values, rows, cols) == expected)
        std::cout << testName << ": solution2 passed." << std::endl;
    else
        std::cout << testName << ": solution2 FAILED." << std::endl;
}

void MaxValueOfGiftsTest1()
{
    int values[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int expected = 29;
    MaxValueOfGiftsTest("test1", (const int *)values, 3, 3, expected);
}