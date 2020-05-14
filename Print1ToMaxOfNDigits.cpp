#include "Print1ToMaxOfNDigits.h"
#include <cstdio>
#include <cstring>
#include <memory>

void PrintNumber(char *number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if (!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }
    printf("\t");
}

bool Increment(char *number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);

    for (int i = nLength - 1; i >= 0; --i)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;

        if (nSum >= 10)
        {
            if (i == 0)
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

void Print1ToMaxOfNDigitsRecusively(char *number, int length, int index)
{
    if (index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecusively(number, length, index + 1);
    }
}

void Print1ToMaxOfNDigits_1(int n)
{
    if (n <= 0)
        return;

    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';
    while (!Increment(number))
    {
        PrintNumber(number);
    }
    delete[] number;
}

void Print1ToMaxOfNDigits_2(int n)
{
    if (n <= 0)
        return;
    char *number = new char[n + 1];
    number[n] = '\0';
    for (int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecusively(number, n, 0);
    }
    delete[] number;
}

void Print1ToMaxOfNDigitsTest(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);

    printf("\nTest for %d ends.\n", n);
}

void Print1ToMaxOfNDigitsTest1()
{
    Print1ToMaxOfNDigitsTest(1);
    Print1ToMaxOfNDigitsTest(2);
    Print1ToMaxOfNDigitsTest(3);
    Print1ToMaxOfNDigitsTest(0);
    Print1ToMaxOfNDigitsTest(-1);
}