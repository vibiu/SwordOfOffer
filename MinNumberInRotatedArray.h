#if !defined(MIN_NUMBER_IN_ROTATED_ARRAY)
#define MIN_NUMBER_IN_ROTATED_ARRAY

int TMin(int *numbers, int length);

int MinInOrder(int *numbers, int index1, int index2);

void MinNumberInRotatedArrayTest(int *numbers, int length, int expected);

void MinNumberInRotatedArrayTest1();
#endif // MIN_NUMBER_IN_ROTATED_ARRAY
