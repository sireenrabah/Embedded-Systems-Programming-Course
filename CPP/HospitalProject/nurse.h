#ifndef __NURSE_H__
#define __NURSE_H__

#include "employee.h"

class Department;

class Nurse : public Employee
{
private:
    int         yearsOfExperience;
    Department* department;

public:
    Nurse(const char* name, int yearsOfExperience);
    Nurse(const Nurse& other);
    Nurse& operator=(const Nurse& other);
    virtual ~Nurse() = default;

    int getYearsOfExperience() const { return yearsOfExperience; }
    bool setYearsOfExperience(int years);

    Department* getDepartment() const { return department; }
    void setDepartment(Department* dep) { department = dep; }

    virtual void print() const override;
};

#endif
