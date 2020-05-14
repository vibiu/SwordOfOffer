#include "LeftRotateString.h"
#include "utils/StringUtil.h"
#include <cstdio>
#include <cstring>

char *LeftRotateString(char *pStr, int n)
{
    if (pStr != nullptr)
    {
        int nLength = static_cast<int>(strlen(pStr));
        if (nLength > 0 && n > 0 && n < nLength)
        {
            char *pFirstStart = pStr;
            char *pFirstEnd = pStr + n - 1;

            char *pSecondStart = pStr + n;
            char *pSecondEnd = pStr + nLength - 1;

            ReverseString(pFirstStart, pFirstEnd);
            ReverseString(pSecondStart, pSecondEnd);
            ReverseString(pFirstStart, pSecondEnd);
        }
    }
    return pStr;
}

void LeftRotateStringTest(const char *testName, char *input, int num, const char *expectedResult)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    char *result = LeftRotateString(input, num);

    if ((input == nullptr && expectedResult == nullptr) || (input != nullptr && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void LeftRotateStringTest1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    LeftRotateStringTest("Test1", input, 2, expected);
}
