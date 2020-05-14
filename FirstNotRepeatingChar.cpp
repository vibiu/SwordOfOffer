#include "FirstNotRepeatingChar.h"
#include <cstdio>

char FirstNotRepeatingChar(const char *pString)
{
    if (pString == nullptr)
        return '\0';

    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for (unsigned int i = 0; i < tableSize; ++i)
        hashTable[i] = 0;
    const char *pHashKey = pString;
    while (*(pHashKey) != '\0')
        hashTable[*(pHashKey++)]++;
    pHashKey = pString;
    while (*pHashKey != '\0')
    {
        if (hashTable[*pHashKey] == 1)
            return *pHashKey;

        pHashKey++;
    }

    return '\0';
}

void FirstNotRepeatingCharTest(const char *pString, char expected)
{
    if (FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

void FirstNotRepeatingCharTest1()
{
    // 常规输入测试，存在只出现一次的字符
    FirstNotRepeatingCharTest("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    FirstNotRepeatingCharTest("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    FirstNotRepeatingCharTest("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    FirstNotRepeatingCharTest(nullptr, '\0');
}