#include "Accumulate.h"
#include <cstdio>

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n)
{
    Temp::Reset();

    Temp *a = new Temp[n];

    delete[] a;
    return Temp::GetSum();
}

A *Array[2];

unsigned int B::Sum(unsigned int n)
{
    return Array[!!n]->Sum(n - 1) + n;
}

unsigned int Sum_Solution2(int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->Sum(n);

    return value;
}

unsigned int Solution3_Teminator(unsigned int n)
{
    return 0;
}

unsigned int Sum_Solution3(unsigned n)
{
    static fun f[2] = {Solution3_Teminator, Sum_Solution3};
    return n + f[!!n](n - 1);
}

void AccumulateTest(int n, int expected)
{
    printf("Test for %d begins:\n", n);

    if (Sum_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if (Sum_Solution2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    if (Sum_Solution3(n) == expected)
        printf("Solution3 passed.\n");
    else
        printf("Solution3 failed.\n");
}

void AccumulateTest1()
{
    const unsigned int number = 1;
    int expected = 1;
    AccumulateTest(number, expected);
    if (Sum_Solution4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}