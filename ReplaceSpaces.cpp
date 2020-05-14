#include <cstdio>
#include <cstring>

#include "ReplaceSpaces.h"

void ReplaceBlank(char str[], int length)
{
    if (str == nullptr && length <= 0)
        return;

    /*originalLength 为字符串str的实际长度*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        ++originalLength;

        if (str[i] == ' ')
            ++numberOfBlank;

        ++i;
    }

    /*newLength 为把空格替换成'%20'之后的长度*/
    int newLength = originalLength + numberOfBlank * 2;
    if (newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if (str[indexOfOriginal] == ' ')
        {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
        else
        {
            str[indexOfNew--] = str[indexOfOriginal];
        }

        --indexOfOriginal;
    }
}

void ReplaceSpacesTest(const char *testName, char str[], int length, const char expected[])
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if (expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if (expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if (strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

void ReplaceSpacesTest1()
{
    const int length = 100;

    char str[length] = "hello world";
    ReplaceSpacesTest("Test1", str, length, "hello%20world");
}