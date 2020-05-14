#if !defined(MAX_IN_SLIDING_WINDOW_H_)
#define MAX_IN_SLIDING_WINDOW_H_

#include <vector>
using std::vector;

vector<int> maxInWindows(const vector<int> &num, unsigned int size);

void MaxInSlidingWindowTest(const char *testName, const vector<int> &num, unsigned int size,
                            const vector<int> &expected);
void MaxInSlidingWindowTest1();

#endif // MAX_IN_SLIDING_WINDOW_H_
