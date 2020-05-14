#include "MinInStack.h"
#include <cassert>
#include <cstdio>

template <typename T> void StackWithMin<T>::push(const T &value)
{
    m_data.push(value);
    if (m_min.size() == 0 || value < m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template <typename T> void StackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    m_data.pop();
    m_min.pop();
}

template <typename T> const T &StackWithMin<T>::min() const
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    return m_min.top();
}

template <typename T> T &StackWithMin<T>::top()
{
    return m_data.top();
}

template <typename T> const T &StackWithMin<T>::top() const
{
    return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
    return m_data.size();
}

void MinInStackTest(const char *testName, const StackWithMin<int> &stack, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void MinInStackTest1()
{
    StackWithMin<int> stack;

    stack.push(3);
    MinInStackTest("Test1", stack, 3);

    stack.push(4);
    MinInStackTest("Test2", stack, 3);

    stack.push(2);
    MinInStackTest("Test3", stack, 2);

    stack.push(3);
    MinInStackTest("Test4", stack, 2);

    stack.pop();
    MinInStackTest("Test5", stack, 2);

    stack.pop();
    MinInStackTest("Test6", stack, 3);

    stack.pop();
    MinInStackTest("Test7", stack, 3);

    stack.push(0);
    MinInStackTest("Test8", stack, 0);
}