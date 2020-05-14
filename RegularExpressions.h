#if !defined(REGULAR_EXPRESSIONS_H_)
#define REGULAR_EXPRESSIONS_H_
bool matchCore(const char *str, const char *pattern);

bool match(const char *str, const char *pattern);

void RegularExpressionsTest(const char *testName, const char *string, const char *pattern, bool expected);

void RegularExpressionsTest1();

#endif // REGULAR_EXPRESSIONS_H_
