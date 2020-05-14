#if !defined(LONGEST_SUBSTRING_WITHOUT_DUP_H_)
#define LONGEST_SUBSTRING_WITHOUT_DUP_H_

#include <string>

bool hasDuplication(const std::string &str, int position[]);

int longestSubstringWithoutDuplication_1(const std::string &str);

int longestSubstringWithoutDuplication_2(const std::string &str);

void LongestSubstringWithoutDupSolution1Test(const std::string &input, int expected);
void LongestSubstringWithoutDupSolution2Test(const std::string &input, int expected);

void LongestSubstringWithoutDupTest(const std::string &input, int expected);

void LongestSubstringWithoutDupTest1();
#endif // LONGEST_SUBSTRING_WITHOUT_DUP_H_
