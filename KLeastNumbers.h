#if !defined(K_LEAST_NUMBERS_H_)
#define K_LEAST_NUMBERS_H_
#include <functional>
#include <set>
#include <vector>

using std::multiset;
using std::vector;

typedef multiset<int, std::greater<int>> intSet;
typedef multiset<int, std::greater<int>>::iterator setIterator;

void GetLeastNumbers_Solution1(int *input, int n, int *output, int k);

void GetLeastNumbers_Solution2(const vector<int> &data, intSet &leastNumbers, int k);

void KLeastNumbersTest(const char *testName, int *data, int n, int *expectedResult, int k);

void KLeastNumbersTest1();

#endif // K_LEAST_NUMBERS_H_
