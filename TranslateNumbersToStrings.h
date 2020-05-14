#if !defined(TRANSLTE_NUMBERS_TO_STRINGS_H_)
#define TRANSLTE_NUMBERS_TO_STRINGS_H_
#include <string>

using std::string;

int GetTranslationCount(const string &number);

int GetTranslationCount(int number);

void TranslateNumbersToStringsTest(const string &testName, int number, int expected);

void TranslateNumbersToStringsTest1();

#endif // TRANSLTE_NUMBERS_TO_STRINGS_H_
