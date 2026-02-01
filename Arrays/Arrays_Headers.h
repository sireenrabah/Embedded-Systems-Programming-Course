#ifndef ARRAYS_HEADERS_H
#define ARRAYS_HEADERS_H
#include <stddef.h>
#include <stdio.h>
/*
   Return codes / Errors
*/
#define OK                 1

#define NULL_ARRAY_ERROR  -1
#define SIZE_ERROR        -2
#define FACTORIAL_ERROR   -3

/* 
Function Prototypes


Description -
Calculates the average value of elements in an integer array
using integer division.

Input -
arr  : Array of integers.
size : Number of elements in the array.

Output -
Returns the integer average of the array elements.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/
int ArrayAverage(int arr[], int size);


/*
Description -
Calculates the factorial of a given integer number.

Input -
n : Integer number received from keyboard.

Output -
Returns the factorial value of n.

Error -
FACTORIAL_ERROR : n is negative.
*/
int Factorial(int n);



/*
Description -
Checks whether an integer number is a palindrome.

Input -
n : Integer number.

Output -
Returns 1 if the number is palindrome, otherwise 0.
*/
int IsPalindrome(int n);


/*
Description -
Checks whether all digits of an integer number are in ascending order.

Input -
n : Integer number.

Output -
Returns 1 if digits are in ascending order, otherwise 0.
*/
int IsAscendingDigits(int n);


/*
Description -
Checks whether a positive integer number is a prime number.

Input -
n : Positive integer number.

Output -
Returns 1 if the number is prime, otherwise 0.
*/
int IsPrime(int n);


/*
Description -
Reverses the digits of a given integer number.

Input -
n : Integer number.

Output -
Returns the reversed number.
*/
int ReverseNumber(int n);


/*
Description -
Checks how many digits of the check number appear in the base number
in the same place and how many appear in different places.

Input -
base  : Positive integer base number (with unique digits).
check : Positive integer check number (with unique digits).

Output -
Returns a two-digit integer:
tens  - count of digits in the same place
ones  - count of digits in different places

Error -
Returns -1 in case of invalid input.
*/
int CheckDigitsMatch(int base, int check);

/*
Description -
Finds the value that appears the most times in an integer array.

Input -
arr  : Array of integers.
size : Number of elements in the array.

Output -
Returns the integer value that occurs most frequently in the array.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/
int MostFrequent(int arr[], int size);

/*
Description -
Reorders the array so that all even numbers appear first and all odd numbers appear after them.
The relative order of the even numbers is preserved, and the relative order of the odd numbers
is preserved (stable partition). Negative numbers are allowed.

Input -
arr  : Array of integers.
size : Number of elements in the array.

Output -
Reorders the array in-place and returns the number of even elements.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/
int EvensFirstOddsAfter(int arr[], int size);

/*
Description -
Sorts an array of integers in ascending order.

Input -
arr  : Array of integers.
size : Number of elements in the array.

Output -
Sorts the array in-place.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/
int SortAscending(int arr[], int size);

/*
Description -
Sorts an array containing only 0's and 1's so that all 0's appear first
followed by all 1's.

Input -
arr  : Array containing only 0 and 1 values.
size : Number of elements in the array.

Output -
Sorts the array in-place.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/
int SortZeroOne(int arr[], int size);

/*
Description -
Searches for a value in a sorted array of integers using binary search.

Input -
arr   : Sorted array of integers (ascending order).
size  : Number of elements in the array.
value : Value to search for.

Output -
Returns the index of the value if found, otherwise returns -1.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/
int BinarySearch(int arr[], int size, int value);

/*
Description -
Finds and returns the median value of an integer array without modifying
the array and without using an auxiliary array.

Input -
arr  : Array of integers.
size : Number of elements in the array.

Output -
Returns the median value.
If the number of elements is even, returns the integer average of the two
middle values.

Error -
NULL_ARRAY_ERROR : arr is NULL.
SIZE_ERROR       : size is less than or equal to 0.
*/
int FindMedian(int arr[], int size);


#endif /* ARRAYS_HEADERS_H */
