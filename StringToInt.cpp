#include "StringToInt.h"
#include <cstdio>

int g_nStatus = kValid;

long long StrToIntCore(const char *digit, bool minus)
{
    long long num = 0;

    while (*digit != '\0')
    {
        if (*digit >= '0' && *digit <= '9')
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');

            if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
            {
                num = 0;
                break;
            }
            digit++;
        }
        else
        {
            num = 0;
            break;
        }
    }
    if (*digit == '\0')
        g_nStatus = kValid;

    return num;
}

int StrToInt(const char *str)
{
    g_nStatus = kInvalid;
    long long num = 0;
    if (str != nullptr && *str != '\0')
    {
        bool minus = false;
        if (*str == '+')
            str++;
        else if (*str == '-')
        {
            str++;
            minus = true;
        }
        if (*str != '\0')
            num = StrToIntCore(str, minus);
    }
    return (int)num;
}

void StringToIntTest(const char *string)
{
    int result = StrToInt(string);
    if (result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

void StringToIntTest1()
{
    StringToIntTest(nullptr);

    StringToIntTest("");

    StringToIntTest("123");

    StringToIntTest("+123");

    StringToIntTest("-123");

    StringToIntTest("1a33");

    StringToIntTest("+0");

    StringToIntTest("-0");

    //有效的最大正整数, 0x7FFFFFFF
    StringToIntTest("+2147483647");

    StringToIntTest("-2147483647");

    StringToIntTest("+2147483648");

    //有效的最小负整数, 0x80000000
    StringToIntTest("-2147483648");

    StringToIntTest("+2147483649");

    StringToIntTest("-2147483649");

    StringToIntTest("+");

    StringToIntTest("-");
}
