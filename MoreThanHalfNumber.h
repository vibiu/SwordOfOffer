#if !defined(MORE_THAN_HALF_NUMBER_H_)
#define MORE_THAN_HALF_NUMBER_H_
#include "utils/Array.h"
bool CheckInvalidArray(int *numbers, int length);

bool checkMoreThanHalf(int *numbers, int length, int number);

int MoreThanHalfNum_Solution1(int *numbers, int length);

int MoreThanHalfNum_Solution2(int *numbers, int length);

void MoreThanHalfNumberTest(const char *testName, int *numbers, int length, int expectedValue, bool expectedFlag);

void MoreThanHalfNumberTest1();

#endif // MORE_THAN_HALF_NUMBER_H_
