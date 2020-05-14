#if !defined(ACCUMULATE_H_)
#define ACCUMULATE_H_

class Temp
{
  public:
    Temp()
    {
        ++N;
        Sum += N;
    }
    static void Reset()
    {
        N = 0;
        Sum = 0;
    }
    static unsigned int GetSum()
    {
        return Sum;
    }

  private:
    static unsigned int N;
    static unsigned int Sum;
};

unsigned int Sum_Solution1(unsigned int n);

class A
{
  public:
    virtual unsigned int Sum(unsigned int n){
        return 0;
    }
};

class B : public A
{
  public:
    virtual unsigned int Sum(unsigned int n);
};

unsigned int Sum_Solution2(int n);

typedef unsigned int (*fun)(unsigned int);
unsigned int Solution3_Teminator(unsigned int n);

unsigned int Sum_Solution3(unsigned n);

template <unsigned int n> struct Sum_Solution4
{
    enum Value
    {
        N = Sum_Solution4<n - 1>::N + n
    };
};

template <> struct Sum_Solution4<1>
{
    enum Value
    {
        N = 1
    };
};

template <> struct Sum_Solution4<0>
{
    enum Value
    {
        N = 0
    };
};

void AccumulateTest(int n, int expected);

void AccumulateTest1();

#endif // ACCUMULATE_H_
