#include <iostream>
#include <string.h>

#include "department.h"
#include "doctor.h"
#include "nurse.h"


using namespace std;
   

Department:: Department (const char* name ) 
: name (nullptr),
Doctorarr(nullptr), physicalNumOfDoctor(2), logicalNumOfDoctor(0),
Nursearr(nullptr),  physicalNumOfNurse(2), logicalNumOfNurse(0) ///constrastor
   {
    cout << "Craeting Department: "<< name << "\n";

    setname(name);

    Doctorarr=new Doctor*[physicalNumOfDoctor];
    for(int i=0;i<physicalNumOfDoctor;i++)
    {
        Doctorarr[i]=nullptr;
    }
    
    Nursearr=new Nurse*[physicalNumOfNurse];
    for(int i=0;i<physicalNumOfNurse;i++)
    {
        Nursearr[i]=nullptr;
    }

   }
    
void Department:: setname(const char* name)
    {
        if (name == nullptr){
        return;
        }  
        delete[]  this->name;   
        this->name = new char[strlen(name) + 1];
        strcpy(this->name , name); 
    }

bool Department::assignDoctor( Doctor& doctor)
{
    for (int i = 0; i < logicalNumOfDoctor; i++)
    if (Doctorarr[i] == &doctor)
        return false;
  
    if(logicalNumOfDoctor==physicalNumOfDoctor)
    {
        physicalNumOfDoctor*=2;
        Doctor** tmp=new Doctor*[physicalNumOfDoctor];
        for(int i=0;i<logicalNumOfDoctor;i++)   //copy the old array
        {
            tmp[i]=Doctorarr[i];
        }
        for (int i = logicalNumOfDoctor; i < physicalNumOfDoctor; i++)
            tmp[i] = nullptr;

        delete []Doctorarr;
        Doctorarr=tmp;
    }
   
    Doctorarr[logicalNumOfDoctor]=&doctor;
    logicalNumOfDoctor++;
    return true;
}

bool Department::assignNurse(Nurse& nurse)
{
    for (int i = 0; i < logicalNumOfNurse; i++)
    if (Nursearr[i] == &nurse)
        return false;


   if(logicalNumOfNurse==physicalNumOfNurse)
    {
        physicalNumOfNurse*=2;
        Nurse** tmp=new Nurse*[physicalNumOfNurse];
        for(int i=0;i<logicalNumOfNurse;i++)   //copy the old array
        {
            tmp[i]=Nursearr[i];
        }
        for (int i = logicalNumOfNurse; i < physicalNumOfNurse; i++)
            tmp[i] = nullptr;

        delete []Nursearr;
        Nursearr=tmp;
    }
   
    Nursearr[logicalNumOfNurse]=&nurse;
    logicalNumOfNurse++;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Department& dep)
{
    os << "\n----- Department Details -----\n";
    os << "Department Name: " << dep.getname() << "\n";

    os << "\nDoctors:\n";
    os << "Number of Doctors: " << dep.logicalNumOfDoctor << "\n";

    for (int i = 0; i < dep.logicalNumOfDoctor; i++)
    {
        if (dep.Doctorarr[i] != nullptr)
            os << *dep.Doctorarr[i] << "\n";
    }

    os << "\nNurses:\n";
    os << "Number of Nurses: " << dep.logicalNumOfNurse << "\n";

    for (int i = 0; i < dep.logicalNumOfNurse; i++)
    {
        if (dep.Nursearr[i] != nullptr)
            os << *dep.Nursearr[i] << "\n";
    }

    os << "-------------------------------\n";

    return os;
}



bool Department::removeDoctor(Doctor& oldDoctor)
{
    for(int i=0; i<logicalNumOfDoctor;i++)
    {
        if( Doctorarr[i]==&oldDoctor)
        {
            for(int j=i;j<logicalNumOfDoctor-1;j++)  //shifing the array left after deleting th doctor
            {
                Doctorarr[j]=Doctorarr[j+1];    
            }
            Doctorarr[logicalNumOfDoctor-1]=nullptr;
            logicalNumOfDoctor--;
            oldDoctor.clearDepartmentPtr();
            return true;
        }
    }
    return false;
}


bool Department::removeNurse(Nurse& oldNurse)
{
    if (logicalNumOfNurse == 0 || Nursearr == nullptr)
        return false;

    for (int i = 0; i < logicalNumOfNurse; i++)
    {
        if (Nursearr[i] == &oldNurse)
        {
            for (int j = i; j < logicalNumOfNurse - 1; j++)
            {
                Nursearr[j] = Nursearr[j + 1];
            }

            Nursearr[logicalNumOfNurse - 1] = nullptr;
            logicalNumOfNurse--;

            oldNurse.clearDepartmentPtr();
            return true;
        }
    }
    return false;
}


Department:: ~Department()//disconstrastor
    {
        delete []name;
        delete []Doctorarr;
        delete []Nursearr;
    }