#include "StringPermutaion.h"
#include <cstdio>

void Permutation(char *pStr, char *pBegin)
{
    if (*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr, pBegin + 1);
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

void Permutation(char *pStr)
{
    if (pStr == nullptr)
        return;
    Permutation(pStr, pStr);
}

void StringPermutaionTest(char *pStr)
{
    if (pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

void StringPermutaionTest1()
{
    StringPermutaionTest(nullptr);

    char string1[] = "";
    StringPermutaionTest(string1);

    char string2[] = "a";
    StringPermutaionTest(string2);

    char string3[] = "ab";
    StringPermutaionTest(string3);

    char string4[] = "abc";
    StringPermutaionTest(string4);
}