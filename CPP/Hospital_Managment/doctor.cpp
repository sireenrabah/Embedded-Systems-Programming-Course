#include <iostream>
#include <string.h>
#include <utility>
using namespace std;

#include "doctor.h"

Doctor:: Doctor(const char* name,const char* specialization,const int id) 
       :Employee(name,id),specialization (nullptr), myDepartment(nullptr)  ///constrastor
   {

    setspecialization(specialization);

   }


Doctor::Doctor(const Doctor& other) noexcept
    : Employee(other), specialization(nullptr), myDepartment(nullptr)
{
    setspecialization(other.specialization);
}


Doctor:: Doctor( Doctor&& other)
   : Employee(std::move(other)), specialization(other.specialization),myDepartment(other.myDepartment)
{
    other.specialization = nullptr;
    other.myDepartment = nullptr;
    
}

Doctor& Doctor::operator=(const Doctor& other)
{
    if (this != &other)
    {
        Employee::operator=(other);
        setspecialization(other.specialization);
        myDepartment = other.myDepartment;
    }
    return *this;
}


Doctor& Doctor::operator=(Doctor&& other) noexcept
{
    if (this != &other)
    {
        Employee::operator=(std::move(other));

        delete[] specialization;
        specialization = other.specialization;
        myDepartment   = other.myDepartment;

        other.specialization = nullptr;
        other.myDepartment = nullptr;
    }
    return *this;
}

bool Doctor::setspecialization(const char* specialization)
{
    if (!specialization) return false;

    char* tmp = new char[strlen(specialization) + 1];
    strcpy(tmp, specialization);

    delete[] this->specialization;
    this->specialization = tmp;
    return true;
}


void Doctor::clearDepartmentPtr()
    {
        myDepartment = nullptr;
    }

bool Doctor::setDepartment(Department* newDepartment)
    {

        if(myDepartment!=newDepartment)
        {
            if(myDepartment!=nullptr)
            {
                myDepartment->removeDoctor(*this);
            }
            
            myDepartment=newDepartment;
            if(myDepartment!=nullptr)
            {
                myDepartment->assignDoctor(*this);
            }
            return true; 
        }  
        return false;

    }



std::ostream& operator<<(std::ostream& os, const Doctor& d)
{
	os << "Doctor Details: \n";
	os << "name: " << d.getname() << "\n";
    os << "Doctor Id: " << d.getid() << "\n";
	os << "Doctor SerialNumber: " << d.getserialnum() << "\n";
	os << "specialization: " << d.getspecialization() << "\n";
	//os << "Department: " << d.myDepartment->getDepartment() << "\n";  //ERROR
    const Department* dep = d.getDepartment();
    if (dep)
        os << "Department: " << dep->getname() << "\n";
    else
        os << "Department: (none)\n";
	return os;
}

Doctor::~Doctor()
{
    if (myDepartment)
        myDepartment->removeDoctor(*this);

    delete[] specialization;
}
