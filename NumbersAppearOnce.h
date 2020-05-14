#if !defined(NUMBERS_APPERAR_ONCE_H_)
#define NUMBERS_APPERAR_ONCE_H_

unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexBit);

void FindNumsAppearOnce(int data[], int length, int *num1, int *num2);

void NumbersAppearOnceTest(const char *testName, int data[], int length, int expected1, int expected2);

void NumbersAppearOnceTest1();

#endif // NUMBERS_APPERAR_ONCE_H_
