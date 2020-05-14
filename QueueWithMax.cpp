#include "QueueWithMax.h"

template <typename T> void QueueWithMax<T>::push_back(T number)
{
    while (!maximums.empty() && number >= maximums.back().number)
        maximums.pop_back();

    InternalData internalData = {number, currentIndex};
    data.push_back(internalData);
    maximums.push_back(internalData);

    ++currentIndex;
}

template <typename T> void QueueWithMax<T>::pop_front()
{
    if (maximums.empty())
        throw new std::runtime_error("queue is empty");
    if (maximums.front().index == data.front().index)
        maximums.pop_front();
    data.pop_front();
}

template <typename T> T QueueWithMax<T>::max() const
{
    if (maximums.empty())
        throw new std::runtime_error("queue is empty");

    return maximums.front().number;
}

void QueueWithMaxTest(const char *testName, const QueueWithMax<int> &queue, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (queue.max() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void QueueWithMaxTest1()
{
    QueueWithMax<int> queue;
    // {2}
    queue.push_back(2);
    QueueWithMaxTest("Test1", queue, 2);

    // {2, 3}
    queue.push_back(3);
    QueueWithMaxTest("Test2", queue, 3);

    // {2, 3, 4}
    queue.push_back(4);
    QueueWithMaxTest("Test3", queue, 4);

    // {2, 3, 4, 2}
    queue.push_back(2);
    QueueWithMaxTest("Test4", queue, 4);

    // {3, 4, 2}
    queue.pop_front();
    QueueWithMaxTest("Test5", queue, 4);

    // {4, 2}
    queue.pop_front();
    QueueWithMaxTest("Test6", queue, 4);

    // {2}
    queue.pop_front();
    QueueWithMaxTest("Test7", queue, 2);

    // {2, 6}
    queue.push_back(6);
    QueueWithMaxTest("Test8", queue, 6);

    // {2, 6, 2}
    queue.push_back(2);
    QueueWithMaxTest("Test9", queue, 6);

    // {2, 6, 2, 5}
    queue.push_back(5);
    QueueWithMaxTest("Test9", queue, 6);

    // {6, 2, 5}
    queue.pop_front();
    QueueWithMaxTest("Test10", queue, 6);

    // {2, 5}
    queue.pop_front();
    QueueWithMaxTest("Test11", queue, 5);

    // {5}
    queue.pop_front();
    QueueWithMaxTest("Test12", queue, 5);

    // {5, 1}
    queue.push_back(1);
    QueueWithMaxTest("Test13", queue, 5);
}