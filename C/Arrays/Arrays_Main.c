#include <stdio.h>
#include "Arrays_Headers.h"

int main(void)
{
    int arr_avg[] = {10, 20, 30, 40, 50};

    /*  Valid array
        NULL array 
        Negative size 
    */
    printf("Valid array result: %d\n", ArrayAverage(arr_avg, 5));
    printf("NULL array result: %d\n", ArrayAverage(NULL, 5));
    printf("Negative size result: %d\n", ArrayAverage(arr_avg, -3));


    

    /*
    Case 1: valid input
    Case 2: negative input
    */
   
    int result_fac;
    result_fac = Factorial(5);
    printf("Factorial(5) = %d\n", result_fac);
    result_fac = Factorial(-5);
    printf("Factorial(-5) = %d\n", result_fac);


    /* 
    Case 1: palindrome number
    Case 2: non-palindrome number
    Case 3: negative number (converted to positive inside func)
    */
    printf("IsPalindrome(12321) = %d\n", IsPalindrome(12321));
    printf("IsPalindrome(12345) = %d\n", IsPalindrome(12345));
    printf("IsPalindrome(-1221) = %d\n", IsPalindrome(-1221));


    /* 
    Case 1: ascending order number
    Case 2: non-ascending order number
    Case 3: negative ascending order number (converted to positive inside func)
    */   

    printf("IsAscendingDigits(1234) = %d\n", IsAscendingDigits(1234));
    printf("IsAscendingDigits(1324) = %d\n", IsAscendingDigits(1324));
    printf("IsAscendingDigits(-4567) = %d\n", IsAscendingDigits(-4567));    


    /*
    Case 1: is prime number
    Case 2: non-prime number
    Case 3&4: 1 and 2 number
    */ 

    printf("IsPrime(7) = %d\n", IsPrime(7));
    printf("IsPrime(9) = %d\n", IsPrime(9));
    printf("IsPrime(1) = %d\n", IsPrime(1));
    printf("IsPrime(2) = %d\n", IsPrime(2));


    /*
    Case 1: reversed postive number
    Case 2: reversed negative number
    */ 

    printf("ReverseNumber(1234) = %d\n", ReverseNumber(1234));
    printf("ReverseNumber(-508) = %d\n", ReverseNumber(-508));


    /*
    Case 1: diffrent place 
    Case 2: same place
    Case : number should have diifrent digits
    */ 
    printf("Result (1234 , 4321) = %d\n", CheckDigitsMatch(1234, 4321));
    printf("Result (2468 , 2648) = %d\n", CheckDigitsMatch(2468, 2648));
    printf("Result (1123 , 3211) = %d\n", CheckDigitsMatch(1123, 3211));


    /*
    Case: find most frequent value
    */
    int arr_freq[] = {2, 5, 2, 7, 5, 2};
    printf("Most frequent value = %d\n", MostFrequent(arr_freq, 6));

    /*
    evens first, odds after (stable)
    */
    int arr_even_odd[] = {3, -2, 4, 7, 0, -5, 8, 1};
    int evenNum = EvensFirstOddsAfter(arr_even_odd, 8);

    printf("Even count = %d\n", evenNum);
    printf("Reordered array: ");
    for (int i = 0; i < 8; i++)
        printf("%d ", arr_even_odd[i]);
    printf("\n");


    /*
    sort array ascending
    */
    int arr_sort[] = {5, -2, 9, 1, 0, -7};
    SortAscending(arr_sort, 6);

    printf("Sorted array: ");
    for (int i = 0; i < 6; i++)
        printf("%d ", arr_sort[i]);
    printf("\n");

    /*
    sort 0 and 1 array
    */
    int arr_zero_one[] = {1, 0, 1, 1, 0, 0, 1};
    SortZeroOne(arr_zero_one, 7);

    printf("Sorted 0/1 array: ");
    for (int i = 0; i < 7; i++)
        printf("%d ", arr_zero_one[i]);
    printf("\n");


    /*
    binary search
    */
    int arr_search[] = {-5, -1, 0, 3, 7, 10, 15};

    printf("Index of 7 = %d\n", BinarySearch(arr_search, 7, 7));
    printf("Index of 4 = %d\n", BinarySearch(arr_search, 7, 4));


    /*
    median
    */
    int arr_median1[] = {7, 1, 3, 9, 5};
    int arr_median2[] = {4, 1, 7, 2};

    printf("Median (odd) = %d\n", FindMedian(arr_median1, 5));
    printf("Median (even) = %d\n", FindMedian(arr_median2, 4));


    return 0;
}
