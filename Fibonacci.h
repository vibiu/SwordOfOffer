#if !defined(FIBONACCI_H_)
#define FIBONACCI_H_

struct Matrix2By2
{
    Matrix2By2(long long m00 = 0, long long m01 = 0, long long m10 = 0, long long m11 = 0)
        : m_00(m00), m_01(m01), m_10(m10), m_11(m11)
    {
    }

    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

Matrix2By2 MatrixMultiply(const Matrix2By2 &matrix1, const Matrix2By2 &matrix2);

Matrix2By2 MatixPower(unsigned int n);

long long Fibonacci_Solution1(unsigned int n);
long long Fibonacci_Solution2(unsigned int n);
long long Fibonacci_Solution3(unsigned int n);

void FibonacciTest(int n, int expected);

void FibonacciTest1();
#endif // FIBONACCI_H_
