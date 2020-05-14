#include "NumberOf1InBinary.h"
#include <cstdio>

int NumberOf1_Solution1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & flag)
            count++;
        flag = flag << 1;
    }
    return count;
}

int NumberOf1_Solution2(int n)
{
    int count = 0;

    while (n)
    {
        ++count;
        n = (n - 1) & n;
    }
    return count;
}

void NumberOf1InBinaryTest(int number, unsigned int expected)
{
    int actual = NumberOf1_Solution1(number);
    if (actual == expected)
        printf("Solution1: Test for %p passed.\n", number);
    else
        printf("Solution1: Test for %p failed.\n", number);

    actual = NumberOf1_Solution2(number);
    if (actual == expected)
        printf("Solution2: Test for %p passed.\n", number);
    else
        printf("Solution2: Test for %p failed.\n", number);

    printf("\n");
}

void NumberOf1InBinaryTest1()
{
    // 输入0，期待的输出是0
    NumberOf1InBinaryTest(0, 0);

    // 输入1，期待的输出是1
    NumberOf1InBinaryTest(1, 1);

    // 输入10，期待的输出是2
    NumberOf1InBinaryTest(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    NumberOf1InBinaryTest(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    NumberOf1InBinaryTest(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    NumberOf1InBinaryTest(0x80000000, 1);
}
