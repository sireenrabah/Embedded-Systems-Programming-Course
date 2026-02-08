#include <stdlib.h>
#include "DynamicArray.h"

int *DynamicArrayCreate(int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    return (int *)malloc(size * sizeof(int));
}

void DynamicArrayDestroy(int *arr)
{
    free(arr);
}

int DynamicArrayInsert(int **arr, int data, int *size, int *count)
{
    int *temp;

    if (*count == *size)
    {
        *size = *size + 1;
        temp = realloc(*arr, *size * sizeof(int));
        if (temp == NULL)
        {
            return 0;
        }
        *arr = temp;
    }

    (*arr)[*count] = data;
    (*count)++;

    return 1;
}

int DynamicArrayDelete(int *arr, int *count)
{
    if (*count == 0)
    {
        return 0;
    }

    (*count)--;
    return 1;
}
