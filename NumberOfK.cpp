#include "NumberOfK.h"
#include <cstdio>

int GetFirstK(const int *data, int length, int k, int start, int end)
{
    if (start > end)
        return -1;

    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];

    if (middleData == k)
    {
        if (middleIndex > 0 && data[middleIndex - 1] != k || middleIndex == 0)
            return middleIndex;
        else
            end = middleIndex - 1;
    }
    else if (middleData > k)
        end = middleIndex - 1;
    else
        start = middleIndex + 1;
    return GetFirstK(data, length, k, start, end);
}

int GetLastK(const int *data, int length, int k, int start, int end)
{
    if (start > end)
        return -1;
    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];

    if (middleData == k)
    {
        if (middleIndex < length - 1 && data[middleIndex + 1] != k || middleIndex == length - 1)
            return middleIndex;
        else
            start = middleIndex + 1;
    }
    else if (middleData < k)
        start = middleIndex + 1;
    else
        end = middleIndex - 1;
    return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(const int *data, int length, int k)
{
    int number = 0;
    if (data != nullptr && length > 0)
    {
        int first = GetFirstK(data, length, k, 0, length - 1);
        int last = GetLastK(data, length, k, 0, length - 1);

        if (first > -1 && last > -1)
            number = last - first + 1;
    }
    return number;
}

void NumberOfKTest(const char *testName, int data[], int length, int k, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void NumberOfKTest1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    NumberOfKTest("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}