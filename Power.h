#if !defined(POWER_H_)
#define POWER_H_

double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent);

double equal(double num1, double num2);

void PowerTest(const char *testName, double base, int exponent, double expectedResult, bool expectedFlag);

void PowerTest1();

#endif // POWER_H_
