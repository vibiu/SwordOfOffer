#include "NumberAppearingOnce.h"
#include <stdexcept>

int FindNumberAppearingOnce(int numbers[], int length)
{
    if (numbers == nullptr || length <= 0)
        throw new std::runtime_error("Invalid input.");

    int bitSum[32] = {0};
    for (int i = 0; i < length; ++i)
    {
        int bitMask = 1;
        for (int j = 31; j >= 0; --j)
        {
            int bit = numbers[i] & bitMask;
            if (bit != 0)
                bitSum[j] += 1;
            bitMask = bitMask << 1;
        }
    }

    int result = 0;
    for (int i = 0; i < 32; ++i)
    {
        result = result << 1;
        result += bitSum[i] % 3;
    }
    return result;
}

void NumberAppearingOnceTest(const char *testName, int numbers[], int length, int expected)
{
    int result = FindNumberAppearingOnce(numbers, length);
    if (result == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s FAILED.\n", testName);
}

void NumberAppearingOnceTest1()
{
    int numbers[] = {1, 1, 2, 2, 2, 1, 3};
    int expected = 3;
    NumberAppearingOnceTest("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}
