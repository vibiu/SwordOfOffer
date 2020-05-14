#include "NumericStrings.h"
#include <cstdio>

bool scanUnsignedInteger(const char **str)
{
    const char *before = *str;
    while (**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);
    return *str > before;
}

bool scanInteger(const char **str)
{
    if (**str == '+' || **str == '-')
        ++(*str);
    return scanUnsignedInteger(str);
}

bool isNumeric(const char *str)
{
    if (str == nullptr)
        return false;

    bool numeric = scanInteger(&str);
    if (*str == '.')
    {
        ++str;
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    if (*str == 'e' || *str == 'E')
    {
        ++str;
        numeric = numeric && scanInteger(&str);
    }
    return numeric && *str == '\0';
}

void NumericStringsTest(const char *testName, const char *str, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void NumericStringsTest1()
{
    NumericStringsTest("Test1", "100", true);
    NumericStringsTest("Test2", "123.45e+6", true);
    NumericStringsTest("Test3", "+500", true);
    NumericStringsTest("Test4", "5e2", true);
    NumericStringsTest("Test5", "3.1416", true);
    NumericStringsTest("Test6", "600.", true);
    NumericStringsTest("Test7", "-.123", true);
    NumericStringsTest("Test8", "-1E-16", true);
    NumericStringsTest("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    NumericStringsTest("Test10", "12e", false);
    NumericStringsTest("Test11", "1a3.14", false);
    NumericStringsTest("Test12", "1+23", false);
    NumericStringsTest("Test13", "1.2.3", false);
    NumericStringsTest("Test14", "+-5", false);
    NumericStringsTest("Test15", "12e+5.4", false);
    NumericStringsTest("Test16", ".", false);
    NumericStringsTest("Test17", ".e1", false);
    NumericStringsTest("Test18", "e1", false);
    NumericStringsTest("Test19", "+.", false);
    NumericStringsTest("Test20", "", false);
    NumericStringsTest("Test21", nullptr, false);
}
