#include <iostream>
#include <string.h>
using namespace std;

#include "doctor.h"


Doctor:: Doctor(const char* name,const char* specialization,const int id) 
       :Employee(name,id),specialization (nullptr), myDepartment(nullptr)  ///constrastor
   {

    setspecialization(specialization);

   }


Doctor::Doctor(const Doctor& other)
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

const Doctor& Doctor:: operator=(const Doctor& other)
   {
    if(this!= &other){
        Employee::operator=(other);
        setspecialization(other.specialization);
        myDepartment = nullptr;
    }
    return *this;

   }

Doctor& Doctor::operator=(Doctor&& other)
{
    if (this != &other)
    {
        Employee::operator=(std::move(other));
        std::swap(specialization, other.specialization);
        std::swap(myDepartment, other.myDepartment);
    }
    return *this;
}


/*
bool Doctor:: setname(const char*name)
    {
        if (name == nullptr){
        return false;
        }                          //should delete it - person\employee responsible
        delete[] this->name;   
         this->name = new char[strlen(name) + 1];
        strcpy( this->name ,name); 
        return true; 
    }
*/


bool Doctor:: setspecialization(const char* specialization)
    {
        if (specialization == nullptr){
            return false;
            }  
        delete[]  this->specialization;   
         this->specialization = new char[strlen(specialization) + 1];
        strcpy( this->specialization, specialization);
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



Doctor:: ~Doctor()      //disconstrastor
    {
        delete []specialization;
    }
    