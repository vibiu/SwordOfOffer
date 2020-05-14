#include "ReverseWordsInSentence.h"

#include "utils/StringUtil.h"
#include <cstdio>
#include <cstring>

char *ReverseSentence(char *pData)
{
    if (pData == nullptr)
        return nullptr;
    char *pBegin = pData;
    char *pEnd = pData;
    while (*pEnd != '\0')
        pEnd++;
    pEnd--;

    ReverseString(pBegin, pEnd);

    pBegin = pEnd = pData;

    while (*pBegin != '\0')
    {

        if (*pBegin == ' ')
        {
            pBegin++;
            pEnd++;
        }
        else if (*pEnd == ' ' || *pEnd == '\0')
        {
            ReverseString(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
            pEnd++;
    }
    return pData;
}

void ReverseWordsInSentenceTest(const char *testName, char *input, const char *expectedResult)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if ((input == nullptr && expectedResult == nullptr) || (input != nullptr && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void ReverseWordsInSentenceTest1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    ReverseWordsInSentenceTest("Test1", input, expected);
}