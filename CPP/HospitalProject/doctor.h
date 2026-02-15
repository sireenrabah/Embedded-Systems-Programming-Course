#ifndef __DOCTOR_H__
#define __DOCTOR_H__

#include "employee.h"

class Department;

class Doctor : public Employee
{
private:
    char*         specialization;
    Department*   department;

public:
    Doctor(const char* name, const char* specialization);
    Doctor(const Doctor& other);
    Doctor&      operator=(const Doctor& other);
    virtual      ~Doctor();

    const char*  getSpecialization() const      { return specialization; }

    Department*  getDepartment() const          { return department; }
    void         setDepartment(Department* dep) { department = dep; }

    virtual void print() const override;
};

#endif
