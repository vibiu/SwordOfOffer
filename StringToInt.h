#if !defined(STRING_TO_INT_H_)
#define STRING_TO_INT_H_

long long StrToIntCore(const char *digit, bool minus);

enum Status
{
    kValid = 0,
    kInvalid
};

int StrToInt(const char *str);

void StringToIntTest(const char *string);

void StringToIntTest1();

#endif // STRING_TO_INT_H_
