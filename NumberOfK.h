#if !defined(NUMBER_OF_K_H_)
#define NUMBER_OF_K_H_

int GetFirstK(const int *data, int length, int k, int start, int end);

int GetLastK(const int *data, int length, int k, int start, int end);

int GetNumberOfK(const int *data, int length, int k);

void NumberOfKTest(const char *testName, int data[], int length, int k, int expected);

void NumberOfKTest1();

#endif // NUMBER_OF_K_H_
