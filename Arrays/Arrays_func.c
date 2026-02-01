#include "Arrays_Headers.h"

int ArrayAverage(int arr[], int size)
{
    int sum = 0;

    if (arr == NULL)
        return NULL_ARRAY_ERROR;

    if (size <= 0)
        return SIZE_ERROR;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size; /* integer average */
}

int Factorial(int n)
{
    int result = 1;

    if (n < 0)
        return FACTORIAL_ERROR;

    while (n > 1)
    {
        result *= n;
        n--;
    }

    return result;
}


int IsPalindrome(int n)
{
    int original = n;
    int reversed = 0;

    if (n < 0)
        n = n *-1;

    while (n > 0)
    {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }

    return (original == reversed);
}


int IsAscendingDigits(int n)
{
    int prevDigit;
    int currDigit;

    if (n < 0)
        n *= -1;

    prevDigit = n % 10;
    n /= 10;

    while (n > 0)
    {
        currDigit = n % 10;

        if (currDigit > prevDigit)
            return 0;

        prevDigit = currDigit;
        n /= 10;
    }

    return 1;
}


int IsPrime(int n)
{
    int i;

    if (n <= 1)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int ReverseNumber(int n)
{
    int reversed = 0;
    int sign = 1;

    if (n < 0)
    {
        sign = -1;
        n *= -1;
    }

    while (n > 0)
    {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }

    return reversed * sign;
}


int CheckDigitsMatch(int base, int check)
{
    int baseDigits[10] = {0};
    int checkDigits[10] = {0};
    int baseArr[10];
    int checkArr[10];
    int len = 0;
    int samePlace = 0;
    int diffPlace = 0;
    int i, j;

    if (base <= 0 || check <= 0)
        return -1;

    /* extract digits */
    while (base > 0 && check > 0)
    {
        baseArr[len] = base % 10;
        checkArr[len] = check % 10;

        if (baseDigits[baseArr[len]] || checkDigits[checkArr[len]])
            return -1;

        baseDigits[baseArr[len]] = 1;
        checkDigits[checkArr[len]] = 1;

        base /= 10;
        check /= 10;
        len++;
    }

    if (base > 0 || check > 0)
        return -1;

    /* same place */
    for (i = 0; i < len; i++)
    {
        if (baseArr[i] == checkArr[i])
            samePlace++;
    }

    /* different place */
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (i != j && baseArr[i] == checkArr[j])
                diffPlace++;
        }
    }

    return (samePlace * 10) + diffPlace;
}


int MostFrequent(int arr[], int size)
{
    if (arr == NULL || size <= 0)
        return -1;

    int maxCount = 0;
    int mostFrequent = arr[0];

    for (int i = 0; i < size; i++)
    {
        int count = 0;

        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    return mostFrequent;
}

int EvensFirstOddsAfter(int arr[], int size)
{
    int temp[1000];          
    int evenCount = 0;
    int k = 0;
    int i;

    if (arr == NULL)
        return NULL_ARRAY_ERROR;

    if (size <= 0)
        return SIZE_ERROR;

    if (size > 1000)
        return SIZE_ERROR;

    /*  זוגיים */
    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            temp[k++] = arr[i];
            evenCount++;
        }
    }

    /*  אי-זוגיים */
    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            temp[k++] = arr[i];
        }
    }

    /* העתקה חזרה */
    for (i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }

    return evenCount;
}

int SortAscending(int arr[], int size)
{
    int i, j, temp;

    if (arr == NULL)
        return NULL_ARRAY_ERROR;

    if (size <= 0)
        return SIZE_ERROR;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return OK;
}

int SortZeroOne(int arr[], int size)
{
    int zeroCount = 0;
    int i;

    if (arr == NULL)
        return NULL_ARRAY_ERROR;

    if (size <= 0)
        return SIZE_ERROR;

    /* count zeros */
    for (i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            zeroCount++;
    }

    /* fill zeros */
    for (i = 0; i < zeroCount; i++)
        arr[i] = 0;

    /* fill ones */
    for (i = zeroCount; i < size; i++)
        arr[i] = 1;

    return OK;
}

int BinarySearch(int arr[], int size, int value)
{
    int left, right, mid;

    if (arr == NULL)
        return NULL_ARRAY_ERROR;

    if (size <= 0)
        return SIZE_ERROR;

    left = 0;
    right = size - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] == value)
            return mid;

        if (value < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;  /* not found */
}

int FindMedian(int arr[], int size)
{
    int i, j;
    int smaller, greater;

    if (arr == NULL)
        return NULL_ARRAY_ERROR;

    if (size <= 0)
        return SIZE_ERROR;

    /* case: odd number of elements */
    if (size % 2 == 1)
    {
        for (i = 0; i < size; i++)
        {
            smaller = 0;
            greater = 0;

            for (j = 0; j < size; j++)
            {
                if (arr[j] < arr[i])
                    smaller++;
                else if (arr[j] > arr[i])
                    greater++;
            }

            if (smaller == size / 2)
                return arr[i];
        }
    }
    else  /* even number of elements */
    {
        int first = 0, second = 0;
        int found = 0;

        for (i = 0; i < size; i++)
        {
            smaller = 0;
            greater = 0;

            for (j = 0; j < size; j++)
            {
                if (arr[j] < arr[i])
                    smaller++;
                else if (arr[j] > arr[i])
                    greater++;
            }

            if (smaller == size / 2 - 1 || smaller == size / 2)
            {
                if (found == 0)
                {
                    first = arr[i];
                    found = 1;
                }
                else
                {
                    second = arr[i];
                    break;
                }
            }
        }

        return (first + second) / 2;
    }

    return SIZE_ERROR; /* should not reach here */
}
