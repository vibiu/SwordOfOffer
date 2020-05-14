#if !defined(QUEUE_WITH_TWO_STACKS_H_)
#define QUEUE_WITH_TWO_STACKS_H_
#include <stack>
using std::stack;

template <typename T> class CQueue
{
  public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T &node);

    T deleteHead();

  private:
    stack<T> stack1;
    stack<T> stack2;
};

void QueueWithTwoStacksTest(const char actual, const char expected);

void QueueWithTwoStacksTest1();

#endif // QUEUE_WITH_TWO_STACKS_H_
