#include <stdio.h>
#include <string.h>
#include "PersonStruct.h"



void GetPersonData(Person *p)
{
    if (p == NULL)
    {
        return;
    }

    printf("Enter name: ");
    scanf(" %29s", p->name);   

    printf("Enter ID: ");
    if (scanf(" %d", &p->id) != 1) return;

    printf("Enter age: ");
    if (scanf(" %d", &p->age) != 1) return;

    printf("Enter education: ");
    if (scanf(" %d", &p->education) != 1) return;
}


void PrintPersonData(const Person *p)
{
    if (p == NULL)
    {
        return;
    }

    printf("Name: %s\n", p->name);
    printf("ID: %d\n", p->id);
    printf("Age: %d\n", p->age);
    printf("Education: %d\n", p->education);
}

/* Step 3: Swap two Persons */
static void SwapPersons(Person *a, Person *b)
{
    Person tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Step 4: Efficient Bubble Sort by Age (ascending) */
void BubbleSortByAge(Person arr[], int n)
{
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].age > arr[j + 1].age)
            {
                SwapPersons(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

/* Step 5: Efficient Bubble Sort by Name (A-Z) */
void BubbleSortByName(Person arr[], int n)
{
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0)
            {
                SwapPersons(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}


void GetStudentBaseData(Student *s)
{
    if (s == NULL)
    {
        return;
    }

    printf("Enter student name: ");
    scanf(" %29s", s->name);

    printf("Enter student ID: ");
    scanf(" %d", &s->id);

    printf("Enter student age: ");
    scanf(" %d", &s->age);
}

void GetStudentGradeInt(Student *s)
{
    if (s == NULL)
    {
        return;
    }

    printf("Enter student grade (int): ");
    scanf(" %d", &s->studentGrade.iGrade);
}

void GetStudentGradeChars(Student *s)
{
    if (s == NULL)
    {
        return;
    }

    printf("Enter student grade (2 chars): ");
    scanf(" %2s", s->studentGrade.sGrade);
}

void PrintStudentIntGrade(const Student *s)
{
    if (s == NULL)
    {
        return;
    }

    printf("Name: %s\n", s->name);
    printf("ID: %d\n", s->id);
    printf("Age: %d\n", s->age);
    printf("Grade (int): %d\n", s->studentGrade.iGrade);
}

void PrintStudentCharGrade(const Student *s)
{
    if (s == NULL)
    {
        return;
    }

    printf("Name: %s\n", s->name);
    printf("ID: %d\n", s->id);
    printf("Age: %d\n", s->age);
    printf("Grade (char): %c%c\n",
           s->studentGrade.sGrade[0],
           s->studentGrade.sGrade[1]);
}

#include <stdlib.h>

DynamicArray* DynamicArrayCreate(int size, int blockSize)
{
    DynamicArray *dArr;

    if (size <= 0 || blockSize <= 0)
    {
        return NULL;
    }

    dArr = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (dArr == NULL)
    {
        return NULL;
    }

    dArr->dArray = (int *)malloc(sizeof(int) * size);
    if (dArr->dArray == NULL)
    {
        free(dArr);
        return NULL;
    }

    dArr->dArraySize = size;
    dArr->dArrayBlockSize = blockSize;
    dArr->NumOfElements = 0;

    return dArr;
}


void DynamicArrayDestroy(DynamicArray *dArr)
{
    if (dArr == NULL)
    {
        return;
    }

    free(dArr->dArray);
    dArr->dArray = NULL;

    free(dArr);
}


DynamicArrayError DynamicArrayInsert(DynamicArray *dArr, int data)
{
    int *temp;

    if (dArr == NULL)
    {
        return DARRAY_NULL_PTR;
    }

    /* Check if array is full */
    if (dArr->NumOfElements == dArr->dArraySize)
    {
        temp = (int *)realloc(dArr->dArray,
                              sizeof(int) * (dArr->dArraySize + dArr->dArrayBlockSize));
        if (temp == NULL)
        {
            return DARRAY_ALLOCATION_FAIL;
        }

        dArr->dArray = temp;
        dArr->dArraySize += dArr->dArrayBlockSize;
    }

    dArr->dArray[dArr->NumOfElements] = data;
    dArr->NumOfElements++;

    return DARRAY_SUCCESS;
}


DynamicArrayError DynamicArrayDelete(DynamicArray *dArr, int *data)
{
    if (dArr == NULL || data == NULL)
    {
        return DARRAY_NULL_PTR;
    }

    if (dArr->NumOfElements == 0)
    {
        return DARRAY_EMPTY;
    }

    dArr->NumOfElements--;
    *data = dArr->dArray[dArr->NumOfElements];

    return DARRAY_SUCCESS;
}
