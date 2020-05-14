#include <iostream>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[high];
//     int i = (low - 1);
//     for (int j = low; j <= high - 1; j++)
//     {
//         if (arr[j] <= pivot)
//         {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     i++;
//     swap(&arr[i], &arr[high]);
//     return i;
// }

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    while (low < high) {
        while(low < high && arr[high] >= pivot) {high--;}
        arr[low] = arr[high];
        while(low < high && arr[low] <= pivot) {low++;}
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {4, 2, 6, 1, 6, 7};
    quickSort(arr, 0, 5);
    for (int i = 0; i < 6; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}