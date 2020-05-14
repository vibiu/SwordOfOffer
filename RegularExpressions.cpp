#include "RegularExpressions.h"
#include <cstdio>

bool matchCore(const char *str, const char *pattern)
{
    if (*str == '\0' && *pattern == '\0')
        return true;
    if (*str != '\0' && *pattern == '\0')
        return false;

    if (*(pattern + 1) == '*')
    {
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
        else
            return matchCore(str, pattern + 2);
    }

    if (*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);

    return false;
}

bool match(const char *str, const char *pattern)
{
    if (str == nullptr || pattern == nullptr)
        return false;

    return matchCore(str, pattern);
}

void RegularExpressionsTest(const char *testName, const char *string, const char *pattern, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void RegularExpressionsTest1()
{
    RegularExpressionsTest("Test01", "", "", true);
    RegularExpressionsTest("Test02", "", ".*", true);
    RegularExpressionsTest("Test03", "", ".", false);
    RegularExpressionsTest("Test04", "", "c*", true);
    RegularExpressionsTest("Test05", "a", ".*", true);
    RegularExpressionsTest("Test06", "a", "a.", false);
    RegularExpressionsTest("Test07", "a", "", false);
    RegularExpressionsTest("Test08", "a", ".", true);
    RegularExpressionsTest("Test09", "a", "ab*", true);
    RegularExpressionsTest("Test10", "a", "ab*a", false);
    RegularExpressionsTest("Test11", "aa", "aa", true);
    RegularExpressionsTest("Test12", "aa", "a*", true);
    RegularExpressionsTest("Test13", "aa", ".*", true);
    RegularExpressionsTest("Test14", "aa", ".", false);
    RegularExpressionsTest("Test15", "ab", ".*", true);
    RegularExpressionsTest("Test16", "ab", ".*", true);
    RegularExpressionsTest("Test17", "aaa", "aa*", true);
    RegularExpressionsTest("Test18", "aaa", "aa.a", false);
    RegularExpressionsTest("Test19", "aaa", "a.a", true);
    RegularExpressionsTest("Test20", "aaa", ".a", false);
    RegularExpressionsTest("Test21", "aaa", "a*a", true);
    RegularExpressionsTest("Test22", "aaa", "ab*a", false);
    RegularExpressionsTest("Test23", "aaa", "ab*ac*a", true);
    RegularExpressionsTest("Test24", "aaa", "ab*a*c*a", true);
    RegularExpressionsTest("Test25", "aaa", ".*", true);
    RegularExpressionsTest("Test26", "aab", "c*a*b", true);
    RegularExpressionsTest("Test27", "aaca", "ab*a*c*a", true);
    RegularExpressionsTest("Test28", "aaba", "ab*a*c*a", false);
    RegularExpressionsTest("Test29", "bbbba", ".*a*a", true);
    RegularExpressionsTest("Test30", "bcbbabab", ".*a*a", false);
}
