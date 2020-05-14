#include "MinNumberInRotatedArray.h"
#include <cstdio>
#include <stdexcept>

int TMin(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        throw std::runtime_error("Invalid parameters");

    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while (numbers[index1] >= numbers[index2])
    {
        if (index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2) / 2;
        if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
            return MinInOrder(numbers, index1, index2);

        if (numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if (numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
    }
    return numbers[indexMid];
}

int MinInOrder(int *numbers, int index1, int index2)
{
    int result = numbers[index1];
    for (int i = index1 + 1; i <= index2; ++i)
    {
        if (result > numbers[i])
            result = numbers[i];
    }
    return result;
}

void MinNumberInRotatedArrayTest(int *numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = TMin(numbers, length);

        for (int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if (result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if (numbers == nullptr)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

void MinNumberInRotatedArrayTest1()
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = {3, 4, 5, 1, 2};
    MinNumberInRotatedArrayTest(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = {3, 4, 5, 1, 1, 2};
    MinNumberInRotatedArrayTest(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = {3, 4, 5, 1, 2, 2};
    MinNumberInRotatedArrayTest(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = {1, 0, 1, 1, 1};
    MinNumberInRotatedArrayTest(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = {1, 2, 3, 4, 5};
    MinNumberInRotatedArrayTest(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = {2};
    MinNumberInRotatedArrayTest(array6, sizeof(array6) / sizeof(int), 2);

    // 输入nullptr
    MinNumberInRotatedArrayTest(nullptr, 0, 0);
}