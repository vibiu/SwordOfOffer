#include "MaxInSlidingWindow.h"
#include <cstdio>
#include <deque>
using std::deque;

vector<int> maxInWindows(const vector<int> &num, unsigned int size)
{
    vector<int> maxInWindows;

    if (num.size() >= size && size >= 1)
    {
        deque<int> index;
        for (unsigned int i = 0; i < size; ++i)
        {
            while (!index.empty() && num[i] >= num[index.back()])
                index.pop_back();

            index.push_back(i);
        }

        for (unsigned int i = size; i < num.size(); ++i)
        {
            maxInWindows.push_back(num[index.front()]);

            while (!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            if (!index.empty() && index.front() <= (int)(i - size))
                index.pop_front();

            index.push_back(i);
        }
        maxInWindows.push_back(num[index.front()]);
    }
    return maxInWindows;
}

void MaxInSlidingWindowTest(const char *testName, const vector<int> &num, unsigned int size,
                            const vector<int> &expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    vector<int> result = maxInWindows(num, size);

    vector<int>::const_iterator iterResult = result.begin();
    vector<int>::const_iterator iterExpected = expected.begin();
    while (iterResult < result.end() && iterExpected < expected.end())
    {
        if (*iterResult != *iterExpected)
            break;

        ++iterResult;
        ++iterExpected;
    }

    if (iterResult == result.end() && iterExpected == expected.end())
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void MaxInSlidingWindowTest1()
{
    int num[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = {4, 4, 6, 6, 6, 5};
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 3;

    MaxInSlidingWindowTest("Test1", vecNumbers, size, vecExpected);
}