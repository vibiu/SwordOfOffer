#include "StringUtil.h"
void ReverseString(char *pBegin, char *pEnd)
{
    if (pBegin == nullptr || pEnd == nullptr)
        return;

    while (pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin++;
        pEnd--;
    }
}
