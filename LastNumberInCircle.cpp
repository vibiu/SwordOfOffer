#include "LastNumberInCircle.h"
#include <cstdio>
#include <list>
using std::list;

int LastRemaining_Solution1(unsigned int n, unsigned int m)
{
    if (n < 1 || m < 1)
        return -1;

    unsigned int i = 0;
    list<int> numbers;

    for (i = 0; i < n; ++i)
        numbers.push_back(i);
    list<int>::iterator current = numbers.begin();
    while (numbers.size() > 1)
    {
        for (int i = 1; i < m; ++i)
        {
            for (int i = 1; i < m; ++i)
            {
                current++;
                if (current == numbers.end())
                    current = numbers.begin();
            }
            list<int>::iterator next = ++current;
            if (next == numbers.end())
                next = numbers.begin();
            --current;
            numbers.erase(current);
            current = next;
        }
    }
    return *(current);
}

int LastRemaining_Solution2(unsigned int n, unsigned int m)
{
    if (n < 1 || m < 1)
        return -1;

    int last = 0;
    for (int i = 2; i <= n; i++)
        last = (last + m) % i;

    return last;
}

void LastNumberInCircleTest(const char *testName, unsigned int n, unsigned int m, int expected)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    if (LastRemaining_Solution1(n, m) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if (LastRemaining_Solution2(n, m) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void LastNumberInCircleTest1()
{
    LastNumberInCircleTest("Test1", 5, 3, 3);
}
