#include "Fibonacci.h"
#include <cstdio>

Matrix2By2 MatrixMultiply(const Matrix2By2 &matrix1, const Matrix2By2 &matrix2)
{
    return Matrix2By2(matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
                      matrix1.m_00 * matrix2.m_10 + matrix1.m_01 * matrix2.m_11,
                      matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
                      matrix1.m_10 * matrix2.m_10 + matrix1.m_11 * matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n)
{
    Matrix2By2 matrix;
    if (n == 1)
    {
        matrix = Matrix2By2(1, 1, 1, 0);
    }
    else if (n % 2 == 0)
    {
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    }
    else if (n % 2 == 1)
    {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }
    return matrix;
}

long long Fibonacci_Solution1(unsigned int n)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
}
long long Fibonacci_Solution2(unsigned int n)
{
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];

    long long fibMinusOne = 1;
    long long fibMinusTwo = 0;
    long long fibN = 0;
    for (unsigned int i = 2; i <= n; ++i)
    {
        fibN = fibMinusOne + fibMinusTwo;
        fibMinusTwo = fibMinusOne;
        fibMinusOne = fibN;
    }
    return fibN;
}
long long Fibonacci_Solution3(unsigned int n)
{
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];

    Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
    return PowerNMinus2.m_00;
}

void FibonacciTest(int n, int expected)
{
    if (Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if (Fibonacci_Solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if (Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
}

void FibonacciTest1()
{
    FibonacciTest(0, 0);
    FibonacciTest(1, 1);
    FibonacciTest(2, 1);
    FibonacciTest(3, 2);
    FibonacciTest(4, 3);
    FibonacciTest(5, 5);
    FibonacciTest(6, 8);
    FibonacciTest(7, 13);
    FibonacciTest(8, 21);
    FibonacciTest(9, 34);
    FibonacciTest(10, 55);

    FibonacciTest(40, 102334155);
}