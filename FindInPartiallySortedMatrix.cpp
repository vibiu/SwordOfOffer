#include "FindInPartiallySortedMatrix.h"
#include <cstdio>

bool FindInSortedMatrix(int *matrix, int rows, int columns, int number)
{
    bool found = false;
    if (matrix != nullptr && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0)
        {
            if (matrix[row * columns + column] == number)
            {
                found = true;
                break;
            }
            else if (matrix[row * columns + column] > number)
                --column;
            else
                ++row;
        }
    }
    return found;
}

void FindInPartiallySortedMatrixTest(const char *testName, int *matrix, int rows, int columns, int number, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    bool result = FindInSortedMatrix(matrix, rows, columns, number);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void FindInPartiallySortedMatrixTest1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    FindInPartiallySortedMatrixTest("Test1", (int *)matrix, 4, 4, 7, true);
}