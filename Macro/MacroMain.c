#include <stdio.h>
#include <time.h>
#include "Macro.h"

#define SIZE 1000
#define RUNS 20

static void InitArray(int* arr)
{
    for (int i = 0; i < SIZE; ++i)
        arr[i] = SIZE - i;
}

static void CopyArray(int* dst, int* src)
{
    for (int i = 0; i < SIZE; ++i)
        dst[i] = src[i];
}

int main(void)
{
    int base[SIZE];
    int a1[SIZE];
    int a2[SIZE];

    clock_t start, end;
    double t_func, t_macro;

    InitArray(base);

    /* ---- Function swap ---- */
    start = clock();
    for (int i = 0; i < RUNS; ++i)
    {
        CopyArray(a1, base);
        BubbleSort_Func(a1, SIZE);
    }
    end = clock();
    t_func = (double)(end - start) / CLOCKS_PER_SEC;

    /* ---- Macro swap ---- */
    start = clock();
    for (int i = 0; i < RUNS; ++i)
    {
        CopyArray(a2, base);
        BubbleSort_Macro(a2, SIZE);
    }
    end = clock();
    t_macro = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Function swap time: %f seconds\n", t_func);
    printf("Macro swap time:    %f seconds\n", t_macro);

    return 0;
}
