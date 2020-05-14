#include "SortArrayForMinNumber.h"
#include <algorithm>
#include <cstdio>
#include <cstring>

const int g_MaxNumberLength = 10;

char *g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char *g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

int compare(const void *strNumber1, const void *strNumber2)
{
    strcpy(g_StrCombine1, *(const char **)strNumber1);
    strcat(g_StrCombine1, *(const char **)strNumber2);

    // [strNumber2][strNumber1]
    strcpy(g_StrCombine2, *(const char **)strNumber2);
    strcat(g_StrCombine2, *(const char **)strNumber1);

    return strcmp(g_StrCombine1, g_StrCombine2);
}

void PrintMinNumber(const int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        return;

    char **strNumbers = (char **)(new int[length]);
    for (int i = 0; i < length; ++i)
    {
        strNumbers[i] = new char[g_MaxNumberLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }

    qsort(strNumbers, length, sizeof(char *), compare);

    for (int i = 0; i < length; ++i)
        printf("%s", strNumbers[i]);
    printf("\n");

    for (int i = 0; i < length; ++i)
        delete[] strNumbers[i];
    delete[] strNumbers;
}

void SortArrayForMinNumberTest(const char *testName, int *numbers, int length, const char *expectedResult)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    if (expectedResult != nullptr)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \t");
    PrintMinNumber(numbers, length);

    printf("\n");
}

void SortArrayForMinNumberTest1()
{
    int numbers[] = {3, 32, 321};
    SortArrayForMinNumberTest("Test2", numbers, sizeof(numbers) / sizeof(int), "321323");
}