#if !defined(TOW_NUMBERS_WITH_SUM_H_)
#define TOW_NUMBERS_WITH_SUM_H_

bool FindNumbersWithSum(int data[], int length, int sum, int *num1, int *num2);

void TwoNumbersWithSumTest(const char *testName, int data[], int length, int sum, bool expectedReturn);

void TwoNumbersWithSumTest1();

#endif // TOW_NUMBERS_WITH_SUM_H_
