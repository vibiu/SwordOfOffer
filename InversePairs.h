#if !defined(INVERSE_PAIRS_H_)
#define INVERSE_PAIRS_H_

int InversePairsCore(int *data, int *copy, int start, int end);

int InversePairs(int *data, int length);

void InversePairsTest(const char *testName, int *data, int length, int expected);

void InversePairsTest1();

#endif // INVERSE_PAIRS_H_
