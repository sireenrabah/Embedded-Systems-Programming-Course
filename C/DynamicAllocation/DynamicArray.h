#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

/* =========================================================================
   DynamicArrayCreate
   =========================================================================
   Description:
   Allocates an integer array of the given size using malloc.

   Parameters:
   size - Number of integers to allocate.

   Returns:
   Pointer to the allocated array, or NULL if allocation failed.
*/
int *DynamicArrayCreate(int size);

/* =========================================================================
   DynamicArrayDestroy
   =========================================================================
   Description:
   Frees a dynamic integer array allocated with DynamicArrayCreate.

   Parameters:
   arr - Pointer to the dynamic array.

   Returns:
   None.
*/
void DynamicArrayDestroy(int *arr);

/* =========================================================================
   DynamicArrayInsert
   =========================================================================
   Description:
   Inserts a value at the end of the dynamic array.
   If the array is full, it grows by one element using realloc.

   Parameters:
   arr   - Address of the array pointer (int **).
   data  - Value to insert.
   size  - Pointer to the current capacity.
   count - Pointer to the current number of elements.

   Returns:
   1 on success, 0 on failure.
*/
int DynamicArrayInsert(int **arr, int data, int *size, int *count);

/* =========================================================================
   DynamicArrayDelete
   =========================================================================
   Description:
   Deletes the last element from the array.

   Parameters:
   arr   - Pointer to the array.
   count - Pointer to the current number of elements.

   Returns:
   1 on success, 0 if the array is empty.
*/
int DynamicArrayDelete(int *arr, int *count);

#endif
