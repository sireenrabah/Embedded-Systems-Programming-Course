#ifndef __NURSE_H__
#define __NURSE_H__

#include "employee.h"

#include <iostream>

class Department;

class Nurse : public Employee
{

private:

    int yearsExperience;

    Department* myDepartment;
    Nurse(const Nurse& )=default;  //copy constrastor
    Nurse& operator=(const Nurse& )=default;
    
    
public:

    Nurse (const char* name,const int yearsExperience,const int id);///constrastor


    //~Nurse();//disconstrastor


    const int getyearsExperience()   const {return yearsExperience;}
    const Department* getDepartment() const {return myDepartment;}
    void clearDepartmentPtr();

    bool setyearsExperience(const int yearsExperience);

    bool setDepartment(Department* newDepartment);
    bool removeDoctor(Nurse& oldNurse);

    friend ostream& operator<<(ostream& os, const Nurse& n);

    virtual Employee* clone() const override { return new Nurse(*this); }


    
};






#endif
