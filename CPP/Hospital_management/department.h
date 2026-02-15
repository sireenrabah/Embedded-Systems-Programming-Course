#ifndef __DEPARTMENT_H__
#define __DEPARTMENT_H__
#include <iostream>


//#include "doctor.h"

class Doctor;
class Nurse;
class Department
{

private:
    char* name;
    Doctor** Doctorarr;
    int physicalNumOfDoctor, logicalNumOfDoctor;

    Nurse** Nursearr;
    int logicalNumOfNurse;
    int physicalNumOfNurse;



    
public:

    Department (const char* Name );    ///constrastor
    Department(const Department&)=delete;     //copy constrastor
    Department& operator=(const Department&)=delete;
    ~Department();      //disconstrastor

    const char* getname()   const {return name;}
    const int getlogicalNumOfDoctor()   const {return logicalNumOfDoctor;}
    void setname(const char* Name);
    bool assignDoctor( Doctor& doctor);
    bool removeDoctor(Doctor& oldDoctor);
    bool assignNurse(Nurse& nurse);
    bool removeNurse(Nurse& oldNurse);
    friend std::ostream& operator<<(std::ostream& os, const Department& dep);

};

#endif
