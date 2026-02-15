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
    Nurse(const Nurse& )=default;  //copy constructor
    Nurse& operator=(const Nurse& )=default;
    
public:

    Nurse (const char* name,const int yearsExperience,const int id);///constructor

    const int getyearsExperience()   const {return yearsExperience;}
    const Department* getDepartment() const {return myDepartment;}
    void clearDepartmentPtr();

    bool setyearsExperience(const int yearsExperience);

    bool setDepartment(Department* newDepartment);

    friend std::ostream& operator<<(std::ostream& os, const Nurse& n);

    virtual Employee* clone() const override { return new Nurse(*this); }

    ~Nurse() override;
};






#endif
