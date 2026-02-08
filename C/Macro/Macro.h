#ifndef MACRO_H
#define MACRO_H

#include <stddef.h>

/* -------- MACRO SWAP -------- */

#define SWAP_MACRO(a,b) do { \
    int temp = (a);          \
    (a) = (b);               \
    (b) = temp;              \
} while (0)



/* -------- FUNCTIONS -------- */


/*
 * Function Name: SwapFunc
 * ----------------------
 * Description:
 * Swaps two integers using a function.
 *
 * Input:
 * a - pointer to first integer
 * b - pointer to second integer
 *
 * Output:
 * None
 *
 * Error:
 * Undefined behavior if a or b is NULL.
 */
void SwapFunc(int* a, int* b);

/*
 * Function Name: BubbleSort_Func
 * ------------------------------
 * Description:
 * Bubble sort using swap FUNCTION.
 *
 * Input:
 * arr  - pointer to int array
 * size - number of elements
 *
 * Output:
 * None
 *
 * Error:
 * If arr is NULL or size is 0 -> does nothing.
 */
void BubbleSort_Func(int* arr, size_t size);


/*
 * Function Name: BubbleSort_Macro
 * -------------------------------
 * Description:
 * Bubble sort using swap MACRO.
 *
 * Input:
 * arr  - pointer to int array
 * size - number of elements
 *
 * Output:
 * None
 *
 * Error:
 * If arr is NULL or size is 0 -> does nothing.
 */
void BubbleSort_Macro(int* arr, size_t size);

#endif
