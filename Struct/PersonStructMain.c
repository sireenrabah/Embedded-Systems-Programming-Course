#include "PersonStruct.h"
#include <stdio.h>
 


int main(void)
{
    /*
    Person person1;
    Person *pPerson1 = &person1;        

    GetPersonData(pPerson1);              ===>>> FOR 1 PERSON
    PrintPersonData(pPerson1);
    */

    Person persons[3] = {0};
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("\n--- Person %d ---\n", i + 1);
        GetPersonData(&persons[i]);
    }

    for (i = 0; i < 3; i++)
    {
        printf("\n--- Print Person %d ---\n", i + 1);
        PrintPersonData(&persons[i]);
    }
    
   struct person p;

    p.u.numOfToys = 5;

    p.u.money = 4015.54;
    printf("%p \n",(void* )&p.u.numOfToys);
    printf("%p \n",(void* )&p.u.money);


    /*Student + Union */

    Student student;
    Student *pStudent = &student;

    GetStudentBaseData(pStudent);

    GetStudentGradeInt(pStudent);
    PrintStudentIntGrade(pStudent);

    GetStudentGradeChars(pStudent);
    PrintStudentCharGrade(pStudent);

    /*Dynamic Array*/

    DynamicArray *dArr;
    int value;

    dArr = DynamicArrayCreate(2, 2);

    DynamicArrayInsert(dArr, 10);
    DynamicArrayInsert(dArr, 20);
    DynamicArrayInsert(dArr, 30); /* realloc happens here */

    DynamicArrayDelete(dArr, &value);
    printf("Deleted value: %d\n", value);

    DynamicArrayDelete(dArr, &value);
    printf("Deleted value: %d\n", value);

    DynamicArrayDestroy(dArr);


    return 0;
}