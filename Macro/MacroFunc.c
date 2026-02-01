#include "Macro.h"

void SwapFunc(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort_Func(int* arr, size_t size)
{
    size_t i, j;

    if (arr == NULL || size == 0)
        return;

    for (i = 0; i < size; ++i)
    {
        for (j = 0; j + 1 < size - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                SwapFunc(&arr[j], &arr[j + 1]);
            }
        }
    }
}


void BubbleSort_Macro(int* arr, size_t size)
{
    size_t i, j;

    if (arr == NULL || size == 0)
        return;

    for (i = 0; i < size; ++i)
    {
        for (j = 0; j + 1 < size - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                SWAP_MACRO(arr[j], arr[j + 1]);
            }
        }
    }
}
