#if !defined(SORT_ARRAY_FOR_MIN_NUMBER_H_)
#define SORT_ARRAY_FOR_MIN_NUMBER_H_

int compare(const void *strNumber1, const void *strNumber2);

void PrintMinNumber(const int *numbers, int length);

void SortArrayForMinNumberTest(const char *testName, int *numbers, int length, const char *expectedResult);

void SortArrayForMinNumberTest1();

#endif // SORT_ARRAY_FOR_MIN_NUMBER_H_
