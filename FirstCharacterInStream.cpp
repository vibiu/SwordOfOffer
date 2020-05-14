#include "FirstCharacterInStream.h"

#include <cstdio>
#include <limits>

using std::numeric_limits;

void CharStatistics::Insert(char ch)
{
    if (occurrence[ch] == -1)
        occurrence[ch] = index;
    else if (occurrence[ch] >= 0)
        occurrence[ch] = -2;
    index++;
}

char CharStatistics::FirstAppearingOnce()
{
    char ch = '\0';
    int minIndex = numeric_limits<int>::max();

    for (int i = 0; i < 256; ++i)
    {
        if (occurrence[i] >= 0 && occurrence[i] < minIndex)
        {
            ch = (char)i;
            minIndex = occurrence[i];
        }
    }
    return ch;
}

void FirstCharacterInStreamTest(const char *testName, CharStatistics chars, char expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (chars.FirstAppearingOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void FirstCharacterInStreamTest1()
{
    CharStatistics chars;

    FirstCharacterInStreamTest("Test1", chars, '\0');

    chars.Insert('g');
    FirstCharacterInStreamTest("Test2", chars, 'g');

    chars.Insert('o');
    FirstCharacterInStreamTest("Test3", chars, 'g');

    chars.Insert('o');
    FirstCharacterInStreamTest("Test4", chars, 'g');

    chars.Insert('g');
    FirstCharacterInStreamTest("Test5", chars, '\0');

    chars.Insert('l');
    FirstCharacterInStreamTest("Test6", chars, 'l');

    chars.Insert('e');
    FirstCharacterInStreamTest("Test7", chars, 'l');
}