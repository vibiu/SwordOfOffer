#include "ConstructArray.h"
#include <cmath>
#include <cstdio>

void BuildProductionArray(const vector<double> &input, vector<double> &output)
{
    int length1 = input.size();
    int length2 = output.size();

    if (length1 == length2 && length2 > 1)
    {
        output[0] = 1;
        for (int i = 1; i < length1; ++i)
        {
            output[i] = output[i - 1] * input[i - 1];
        }
        double temp = 1;
        for (int i = length1 - 2; i >= 0; --i)
        {
            temp *= input[i + 1];
            output[i] *= temp;
        }
    }
}

bool EqualArrays(const vector<double> &input, const vector<double> &output)
{
    int length1 = input.size();
    int length2 = output.size();

    if (length1 != length2)
        return false;

    for (int i = 0; i < length1; ++i)
    {
        if (abs(input[i] - output[i]) > 0.0000001)
            return false;
    }
    return true;
}

void ConstructArrayTest(const char *testName, const vector<double> &input, vector<double> &output,
                        const vector<double> &expected)
{
    printf("%s Begins: ", testName);

    BuildProductionArray(input, output);
    if (EqualArrays(output, expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void ConstructArrayTest1()
{
    vector<double> input = {1, 2, 3, 4, 5};
    vector<double> output = {0, 0, 0, 0, 0};
    vector<double> expected = {120, 60, 40, 30, 24};

    ConstructArrayTest("Test1", input, output, expected);
}
