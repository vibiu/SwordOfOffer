#if !defined(NUMERIC_STRINGS_H_)
#define NUMERIC_STRINGS_H_

bool scanUnsignedInteger(const char **str);

bool scanInteger(const char **str);

bool isNumeric(const char *str);

void NumericStringsTest(const char *testName, const char *str, bool expected);

void NumericStringsTest1();

#endif // NUMERIC_STRINGS_H_
