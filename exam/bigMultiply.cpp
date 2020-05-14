#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using std::string;

string BigMultiply(string number1, string number2)
{
    int i, j;
    int *iresult;
    int length1 = number1.size();
    int length2 = number2.size();

    string result = "";

    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());

    if (length1 == 0 || length2 == 0)
    {
        result = "nil";
        return result;
    }

    iresult = (int *)malloc(sizeof(int) * (length1 + length2 + 1));
    memset(iresult, 0, sizeof(int) * (length1 + length2 + 1));

    for (i = 0; i < length1; ++i)
    {
        for (j = 0; j < length2; j++)
        {
            iresult[i + j] += ((number1[i] - '0') * (number2[i] - '0'));
        }
    }

    int carry = 0;
    for (i = 0; i < length1 + length2; i++)
    {
        int value = iresult[i] + carry;
        iresult[i] = value % 10;
        carry = value / 10;
    }

    for (i = length1 + length2 - 1; i >= 0; i--)
    {
        if (iresult[i] != 0)
            break;
    }

    for (; i >= 0; i--)
    {
        result = result + (char)(iresult[i] + '0');
    }

    free(iresult);

    if (result == "")
        result = "0";
    return result;
}

int main()
{
    string myStr1 = "12345";
    string myStr2 = "12344";
    string result = BigMultiply(myStr1, myStr2);
    std::cout << result << std::endl;
}
