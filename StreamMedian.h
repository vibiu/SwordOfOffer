#if !defined(STREAM_MEDIAN_H_)
#define STREAM_MEDIAN_H_

#include <vector>
using std::vector;

template <typename T> class DynamicArray
{
  public:
    void Insert(T num);

    T GetMedian();

  private:
    vector<T> min;
    vector<T> max;
};

void StreamMedianTest(const char *testName, DynamicArray<double> &numbers, double expected);

void StreamMedianTest1();

#endif // STREAM_MEDIAN_H_
