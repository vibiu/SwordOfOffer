#include "StreamMedian.h"
#include <algorithm>
#include <cstdio>
#include <functional>
#include <stdexcept>

using std::greater;
using std::less;
using std::pop_heap;
using std::push_heap;

template <typename T> void DynamicArray<T>::Insert(T num)
{
    if (((min.size() + max.size()) & 1) == 0)
    {
        if (max.size() > 0 && num < max[0])
        {
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());

            num = max[0];

            pop_heap(max.begin(), max.end(), less<T>());
            max.pop_back();
        }

        min.push_back(num);
        push_heap(min.begin(), min.end(), greater<T>());
    }
    else
    {
        if (min.size() > 0 && min[0] < num)
        {
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());

            num = min[0];

            pop_heap(min.begin(), min.end(), greater<T>());
            min.pop_back();
        }

        max.push_back(num);
        push_heap(max.begin(), max.end(), less<T>());
    }
}

template <typename T> T DynamicArray<T>::GetMedian()
{
    int size = min.size() + max.size();
    if (size == 0)
        throw std::runtime_error("No numbers are available");

    T median = 0;
    if ((size & 1) == 1)
        median = min[0];
    else
        median = (min[0] + max[0]) / 2;

    return median;
}

void StreamMedianTest(const char *testName, DynamicArray<double> &numbers, double expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (abs(numbers.GetMedian() - expected) < 0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void StreamMedianTest1()
{
    DynamicArray<double> numbers;

    printf("Test1 begins: ");
    try
    {
        numbers.GetMedian();
        printf("FAILED.\n");
    }
    catch (const std::runtime_error &)
    {
        printf("Passed.\n");
    }

    numbers.Insert(5);
    StreamMedianTest("Test2", numbers, 5);

    numbers.Insert(2);
    StreamMedianTest("Test3", numbers, 3.5);

    numbers.Insert(3);
    StreamMedianTest("Test4", numbers, 3);

    numbers.Insert(4);
    StreamMedianTest("Test6", numbers, 3.5);

    numbers.Insert(1);
    StreamMedianTest("Test5", numbers, 3);

    numbers.Insert(6);
    StreamMedianTest("Test7", numbers, 3.5);

    numbers.Insert(7);
    StreamMedianTest("Test8", numbers, 4);

    numbers.Insert(0);
    StreamMedianTest("Test9", numbers, 3.5);

    numbers.Insert(8);
    StreamMedianTest("Test10", numbers, 4);
}