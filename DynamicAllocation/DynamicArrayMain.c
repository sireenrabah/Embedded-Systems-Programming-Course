#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

int main(void)
{
    int *arr;
    int size = 2;
    int count = 0;
    int i;

    /* Create dynamic array */
    arr = DynamicArrayCreate(size);
    if (arr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    /* Insert values */
    DynamicArrayInsert(&arr, 10, &size, &count);
    DynamicArrayInsert(&arr, 20, &size, &count);
    DynamicArrayInsert(&arr, 30, &size, &count);

    printf("Array values:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    /* Delete last element */
    DynamicArrayDelete(arr, &count);

    printf("\nAfter delete:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    /* Free memory */
    DynamicArrayDestroy(arr);

    return 0;
}
