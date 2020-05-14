#if !defined(MIN_IN_STACK_H_)
#define MIN_IN_STACK_H_
#include <stack>

template <typename T> class StackWithMin
{
  public:
    StackWithMin()
    {
    }
    virtual ~StackWithMin()
    {
    }

    T &top();
    const T &top() const;

    void push(const T &value);
    void pop();

    const T &min() const;

    bool empty() const;
    size_t size() const;

  private:
    std::stack<T> m_data;
    std::stack<T> m_min;
};

void MinInStackTest(const char *testName, const StackWithMin<int> &stack, int expected);

void MinInStackTest1();

#endif // MIN_IN_STACK_H_
