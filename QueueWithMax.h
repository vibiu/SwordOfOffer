#if !defined(QUEUE_WITH_MAX_H_)
#define QUEUE_WITH_MAX_H_

#include <deque>
#include <stdexcept>

using std::deque;

template <typename T> class QueueWithMax
{
  public:
    QueueWithMax() : currentIndex(0)
    {
    }

    void push_back(T number);

    void pop_front();

    T max() const;

  private:
    struct InternalData
    {
        T number;
        int index;
    };
    deque<InternalData> data;
    deque<InternalData> maximums;
    int currentIndex;
};

void QueueWithMaxTest(const char *testName, const QueueWithMax<int> &queue, int expected);

void QueueWithMaxTest1();

#endif // QUEUE_WITH_MAX_H_
