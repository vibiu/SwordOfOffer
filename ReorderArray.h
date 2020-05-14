#if !defined(RECORDER_ARRAY_H)
#define RECORDER_ARRAY_H
void Recorder(int *pData, unsigned int length, bool (*func)(int));

bool isEven(int n);

void ReorderOddEven_1(int *pData, unsigned int length);

void ReorderOddEven_2(int *pData, unsigned int length);

void Reorder(int *pData, unsigned int length, bool (*func)(int));

void PrintArray(int numbers[], int length);

void ReorderArrayTest(const char *testName, int numbers[], int length);

void ReorderArrayTest1();
#endif // RECORDER_ARRAY_H
