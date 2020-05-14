#if !defined(CONTINOUS_CARD_H_)
#define CONTINOUS_CARD_H_

int Compare(const void *arg1, const void *arg2);

bool IsContinuous(int *numbers, int length);

void ContinousCardTest(const char *testName, int *numbers, int length, bool expected);

void ContinousCardTest1();

#endif // CONTINOUS_CARD_H_
