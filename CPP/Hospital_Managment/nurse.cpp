#include <iostream>
#include <cstring>
using namespace std;

#include "nurse.h"
#include "department.h"

Nurse::Nurse(const char* name,const int  yearsExperience,const int id) 
      : Employee(name,id),
        yearsExperience(yearsExperience),
        myDepartment(nullptr)
{

}

bool Nurse::setyearsExperience(const int yearsExperience)
{
    if (yearsExperience < 0)
        return false;

    this->yearsExperience = yearsExperience;
    return true;
}

void Nurse::clearDepartmentPtr()
    {
        myDepartment = nullptr;
    }

bool Nurse::setDepartment(Department* newDepartment)
    {

        if(myDepartment!=newDepartment)
        {
            if(myDepartment!=nullptr)
            {
                myDepartment->removeNurse(*this);
            }
            
        
            myDepartment=newDepartment;
            if(myDepartment!=nullptr)
            {
                myDepartment->assignNurse(*this);
            }
            return true; 
        }  
        return false;

    }

std::ostream& operator<<(std::ostream& os, const Nurse& n)
{
    os << "Nurse Details:\n";
    os << "name: " << n.getname() << "\n";
    os << "Nurse Id: " << n.getid() << "\n";
    os << "Nurse SerialNumber: " << n.getserialnum() << "\n";
    os << "number of Experience years: " << n.getyearsExperience() << "\n";

    if (n.myDepartment)
        os << "Department: " << n.myDepartment->getname() << "\n";
    else
        os << "Department: (none)\n";

    return os;
}

Nurse::~Nurse()
{
    if (myDepartment)
        myDepartment->removeNurse(*this);
}
