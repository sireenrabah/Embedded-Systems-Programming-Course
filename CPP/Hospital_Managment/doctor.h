#ifndef __DOCTOR_H__
#define __DOCTOR_H__
#include <iostream>

#include "department.h"
#include "employee.h"

class Doctor : virtual public Employee
{

private:

    char* specialization;
    Department* myDepartment;
    
public:

    Doctor (const char* name,const char* specialization,const int id);///constrastor
    Doctor(const Doctor& other) noexcept;//copy constructor
    Doctor( Doctor&& other); //move

    Doctor& operator=(const Doctor& other);
    Doctor& operator=( Doctor&& other) noexcept;
  
    ~Doctor();    //disconstrastor

    virtual Employee* clone() const override {return new Doctor(*this);}

    const char* getspecialization()   const {return specialization;}
    const Department* getDepartment() const {return myDepartment;}
    void clearDepartmentPtr();

    bool setspecialization(const char* Specialization);

    bool setDepartment(Department* newDepartment);


    friend std::ostream& operator<<(std::ostream& os, const Doctor& d);




    
};






#endif
