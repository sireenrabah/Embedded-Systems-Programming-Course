#ifndef __DEPARTMENT_H__
#define __DEPARTMENT_H__
#include <iostream>
#include <vector>

//#include "doctor.h"

class Doctor;
class Nurse;
class Department
{

private:
    char* name;
    std::vector<Doctor*> doctors;
    std::vector<Nurse*> nurses;

public:

    Department (const char* Name );    ///constrastor
    Department(const Department&)=delete;     //copy constrastor
    Department& operator=(const Department&)=delete;
    ~Department();      //disconstrastor

    const char* getname()   const {return name;}
    
    int getNumDoctors() const { return (int)doctors.size(); }
    int getNumNurses()  const { return (int)nurses.size(); }

    void setname(const char* Name);
    bool assignDoctor( Doctor& doctor);
    bool removeDoctor(Doctor& oldDoctor);
    bool assignNurse(Nurse& nurse);
    bool removeNurse(Nurse& oldNurse);
    friend std::ostream& operator<<(std::ostream& os, const Department& dep);

};

#endif
