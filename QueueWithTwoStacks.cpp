#include "QueueWithTwoStacks.h"
#include <stdexcept>

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template <typename T> void CQueue<T>::appendTail(const T &element)
{
    stack1.push(element);
}

template <typename T> T CQueue<T>::deleteHead()
{
    if (stack2.size() <= 0)
    {
        while (stack1.size() > 0)
        {
            T &data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if (stack2.size() == 0)
        throw std::runtime_error("queue is empty");

    T head = stack2.top();
    stack2.pop();
    return head;
}

void QueueWithTwoStacksTest(const char actual, const char expected)
{
    if (actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
};

void QueueWithTwoStacksTest1()
{
    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    QueueWithTwoStacksTest(head, 'a');

    head = queue.deleteHead();
    QueueWithTwoStacksTest(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    QueueWithTwoStacksTest(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    QueueWithTwoStacksTest(head, 'd');

    head = queue.deleteHead();
    QueueWithTwoStacksTest(head, 'e');
};