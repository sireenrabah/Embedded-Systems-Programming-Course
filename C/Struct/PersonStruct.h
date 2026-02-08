#ifndef PERSONSTRUCT_H
#define PERSONSTRUCT_H

/*
 * Struct Name: Person
 * -------------------
 * Description:
 * This structure represents a person and contains personal information.
 *
 * Members:
 * name      - Person name
 * id        - Person ID number
 * age       - Person age
 * education - Person education level
 */
typedef struct
{
    char name[30];
    int id;
    int age;
    int education;
} Person;
union un
{
    int numOfToys;
    float money;
};

struct person
{
    int age;
    union un u;
    char name[32];
};



/*
 * Function Name: GetPersonData
 * ----------------------------
 * Description:
 * This function receives a pointer to a Person structure and
 * reads the person's data from the keyboard.
 *
 * Input:
 * p - Pointer to Person structure
 *
 * Output:
 * None
 *
 * Return:
 * None
 */
void GetPersonData(Person *p);


/*
 * Function Name: PrintPersonData
 * ------------------------------
 * Description:
 * This function receives a pointer to a Person structure and
 * prints the person's data.
 *
 * Input:
 * p - Pointer to Person structure
 *
 * Output:
 * Printed person data
 *
 * Return:
 * None
 */
void PrintPersonData(const Person *p);


/*
 * Union Name: Grade
 * -----------------
 * Description:
 * This union represents a student grade that can be stored
 * either as an integer grade or as a 2-character grade.
 */
union Grade
{
    int  iGrade;
    char sGrade[2];
};

/*
 * Struct Name: Student
 * --------------------
 * Description:
 * This structure represents a student and contains personal
 * information and a grade stored as a union.
 *
 * Members:
 * name         - Student name
 * id           - Student ID
 * age          - Student age
 * studentGrade - Student grade (union Grade)
 */
typedef struct
{
    char name[30];
    int  id;
    int  age;
    union Grade studentGrade;
} Student;


/*
 * Function Name: GetStudentBaseData
 * --------------------------------
 * Description:
 * This function reads the student's basic data (name, id, age)
 * from the keyboard.
 *
 * Input:
 * s - Pointer to Student structure
 *
 * Output:
 * Student base data is updated
 *
 * Return:
 * None
 */
void GetStudentBaseData(Student *s);


/*
 * Function Name: GetStudentGradeInt
 * --------------------------------
 * Description:
 * This function reads an integer grade into the student's grade union.
 *
 * Input:
 * s - Pointer to Student structure
 *
 * Output:
 * Student grade (integer) is updated
 *
 * Return:
 * None
 */
void GetStudentGradeInt(Student *s);


/*
 * Function Name: GetStudentGradeChars
 * ----------------------------------
 * Description:
 * This function reads a 2-character grade into the student's grade union.
 *
 * Input:
 * s - Pointer to Student structure
 *
 * Output:
 * Student grade (char[2]) is updated
 *
 * Return:
 * None
 */
void GetStudentGradeChars(Student *s);


/*
 * Function Name: PrintStudentIntGrade
 * ----------------------------------
 * Description:
 * This function prints student data assuming the grade
 * is stored as an integer.
 *
 * Input:
 * s - Pointer to Student structure
 *
 * Output:
 * Printed student data
 *
 * Return:
 * None
 */
void PrintStudentIntGrade(const Student *s);


/*
 * Function Name: PrintStudentCharGrade
 * -----------------------------------
 * Description:
 * This function prints student data assuming the grade
 * is stored as 2 characters.
 *
 * Input:
 * s - Pointer to Student structure
 *
 * Output:
 * Printed student data
 *
 * Return:
 * None
 */
void PrintStudentCharGrade(const Student *s);

/*
 * Enum Name: DynamicArrayError
 * ----------------------------
 * Description:
 * This enum defines possible error codes for dynamic array operations.
 */
typedef enum
{
    DARRAY_SUCCESS = 0,
    DARRAY_NULL_PTR,
    DARRAY_INVALID_INPUT,
    DARRAY_ALLOCATION_FAIL,
    DARRAY_EMPTY
} DynamicArrayError;


/*
 * Struct Name: DynamicArray
 * -------------------------
 * Description:
 * This structure represents a dynamic array of integers.
 *
 * Members:
 * dArray          - Pointer to dynamically allocated array
 * dArraySize      - Current allocated size
 * dArrayBlockSize - Size to increase when array is full
 * NumOfElements   - Number of elements currently stored
 */
typedef struct
{
    int *dArray;
    int dArraySize;
    int dArrayBlockSize;
    int NumOfElements;
} DynamicArray;


/*
 * Function Name: DynamicArrayCreate
 * --------------------------------
 * Description:
 * This function creates a dynamic array with initial size
 * and block size for growth.
 *
 * Input:
 * size      - Initial array size
 * blockSize - Block size for resizing
 *
 * Output:
 * None
 *
 * Return:
 * Pointer to DynamicArray on success, NULL on failure
 */
DynamicArray* DynamicArrayCreate(int size, int blockSize);


/*
 * Function Name: DynamicArrayDestroy
 * ---------------------------------
 * Description:
 * This function frees all memory of the dynamic array.
 *
 * Input:
 * dArr - Pointer to DynamicArray
 *
 * Output:
 * None
 *
 * Return:
 * None
 */
void DynamicArrayDestroy(DynamicArray *dArr);


/*
 * Function Name: DynamicArrayInsert
 * --------------------------------
 * Description:
 * This function inserts a value into the dynamic array.
 * If the array is full, it increases its size.
 *
 * Input:
 * dArr - Pointer to DynamicArray
 * data - Value to insert
 *
 * Output:
 * Dynamic array updated
 *
 * Return:
 * DynamicArrayError
 */
DynamicArrayError DynamicArrayInsert(DynamicArray *dArr, int data);


/*
 * Function Name: DynamicArrayDelete
 * --------------------------------
 * Description:
 * This function deletes the last element from the dynamic array.
 *
 * Input:
 * dArr - Pointer to DynamicArray
 * data - Pointer to store deleted value
 *
 * Output:
 * Deleted value stored in data
 *
 * Return:
 * DynamicArrayError
 */
DynamicArrayError DynamicArrayDelete(DynamicArray *dArr, int *data);


#endif /* PERSONSTRUCT_H */