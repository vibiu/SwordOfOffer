#include "KLeastNumbers.h"
#include "utils/Array.h"
#include <iostream>

void GetLeastNumbers_Solution1(int *input, int n, int *output, int k)
{
    if (input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
        return;

    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while (index != k - 1)
    {
        if (index > k - 1)
        {
            end = index - 1;
            index = Partition(input, n, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }

    for (int i = 0; i < k; ++i)
        output[i] = input[i];
}

void GetLeastNumbers_Solution2(const vector<int> &data, intSet &leastNumbers, int k)
{
    leastNumbers.clear();
    if (k < 1 || data.size() < k)
        return;

    vector<int>::const_iterator iter = data.begin();
    for (; iter != data.end(); ++iter)
    {
        if (leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else
        {
            setIterator iterGreatest = leastNumbers.begin();
            if (*iter < *(leastNumbers.begin()))
            {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}

void KLeastNumbersTest(const char *testName, int *data, int n, int *expectedResult, int k)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    vector<int> vectorData;
    for (int i = 0; i < n; ++i)
        vectorData.push_back(data[i]);

    if (expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else
    {
        printf("Expected result: \n");
        for (int i = 0; i < k; ++i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    printf("Result for solution1:\n");
    int *output = new int[k];
    GetLeastNumbers_Solution1(data, n, output, k);
    if (expectedResult != nullptr)
    {
        for (int i = 0; i < k; ++i)
            printf("%d\t", output[i]);
        printf("\n");
    }

    delete[] output;

    printf("Result for solution2:\n");
    intSet leastNumbers;
    GetLeastNumbers_Solution2(vectorData, leastNumbers, k);
    printf("The actual output numbers are:\n");
    for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        printf("%d\t", *iter);
    printf("\n\n");
}

void KLeastNumbersTest1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    KLeastNumbersTest("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}