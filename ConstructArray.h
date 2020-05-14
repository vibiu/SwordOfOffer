#if !defined(CONSTRUCT_ARRAY_H_)
#define CONSTRUCT_ARRAY_H_
#include <vector>

using std::vector;

void BuildProductionArray(const vector<double> &input, vector<double> &output);

bool EqualArrays(const vector<double> &input, const vector<double> &output);

void ConstructArrayTest(const char *testName, const vector<double> &input, vector<double> &output,
                        const vector<double> &expected);

void ConstructArrayTest1();

#endif // CONSTRUCT_ARRAY_H_
