#if !defined(STACK_PUSH_POP_ORDER_H_)
#define STACK_PUSH_POP_ORDER_H_
bool IsPopOrder(const int *pPush, const int *pPop, int nLength);

void StackPushPopOrderTest(const char *testName, const int *pPush, const int *pPop, int nLength, bool expected);

void StackPushPopOrderTest1();

#endif // STACK_PUSH_POP_ORDER_H_
