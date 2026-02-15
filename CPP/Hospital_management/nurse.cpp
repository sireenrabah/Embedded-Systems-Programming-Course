#include <iostream>
#include <string.h>
using namespace std;

#include "nurse.h"
#include "department.h"

Nurse::Nurse(const char* name,const int  yearsExperience,const int id) 
      : Employee(name,id),
        yearsExperience(yearsExperience),
        myDepartment(nullptr)
{

}
    
/*octor:: Doctor(const Doctor& other)  : Employee(other), specialization (nullptr)
   {
        *this=other;
       
   
   }

const Doctor& Doctor:: operator=(const Doctor& other)
   {
    if(this!= &other){

        setspecialization(other.specialization);
    }
    return *this;

   }*/



 
bool Nurse:: setyearsExperience(const int yearsExperience)
{
    if(this->yearsExperience<yearsExperience)
    {
       this->yearsExperience=yearsExperience ;
        return true; 
    }
     return false; 
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

/*
bool Department::removeNurse(Nurse& oldNurse)
{
    for(int i=0; i<logicalNumOfNurse;i++)
    {
        if( Nursearr[i]==&oldNurse)
        {
            for(int j=i;j<logicalNumOfNurse-1;j++)
            {
                Nursearr[j]=Nursearr[j+1];    
            }
            Nursearr[logicalNumOfNurse-1]=nullptr;
            logicalNumOfNurse--;
            oldNurse.clearDepartmentPtr();
            return true;
        }
    }
    return false;
}
*/

ostream& operator<<(ostream& os, const Nurse& d)
{
	os << "Nurse Details: \n";
	os << "name: " << d.getname() << "\n";
    os << "Nurse Id: " << d.getid() << "\n";
	os << "Nurse SerialNumber: " << d.getserialnum() << "\n";
	os << "number of Experience years: " << d.getyearsExperience() << "\n";
	//os << "Department: " << d.myDepartment->getDepartment() << "\n";
	if (d.myDepartment) os <<"Department: " << d.myDepartment->getname();
    else os << "(none)";
    return os;
}



