#include "Array.h"
#include <cstdlib>
#include <stdexcept>

int RandomInrange(int min, int max)
{
    int random = rand() % (max - min + 1) + min;
    return random;
}

void Swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int Partition(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start < 0 || end >= length)
        throw std::runtime_error("Invalid Parameters");

    int index = RandomInrange(start, end);
    Swap(&data[index], &data[end]);

    int small = start - 1;

    for (index = start; index < end; ++index)
    {
        if (data[index] < data[end])
        {
            ++small;
            if (small != index)
                Swap(&data[index], &data[small]);
        }
    }
    ++small;
    Swap(&data[small], &data[end]);
    return small;
}
