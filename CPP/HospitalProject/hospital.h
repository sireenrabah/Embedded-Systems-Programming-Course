#ifndef __HOSPITAL_H__
#define __HOSPITAL_H__

#include "doctor.h"
#include "department.h"
#include "nurse.h"

class Hospital
{
private:
    char*        name;
    int          physicalNumOfDoc;
    int          physicalNumOfDep;
    int          logicalNumOfDoc;
    int          logicalNumOfDep;
    int          physicalNumOfNurses;
    int          logicalNumOfNurses;
    Doctor**     doctors;
    Department** departments;
    Nurse**      nurses;

public:
    Hospital(const char* name);
    Hospital(const Hospital&) = delete;
    Hospital& operator=(const Hospital&) = delete;
    ~Hospital();

    const char* getName() const { return name; }
    int getPhysicalNumOfDoctor() const { return physicalNumOfDoc; }
    int getPhysicalNumOfDepartment() const { return physicalNumOfDep; }
    int getLogicalNumOfDepartment() const { return logicalNumOfDep; }
    int getLogicalNumOfDoctor() const { return logicalNumOfDoc; }

    bool setName(const char* name);
    bool addDepartment(const char* name);
    bool addDoctor(const Doctor& doctor, const char* departmentName);
    bool addNurse(const char* name, int yearsOfExperience, const char* departmentName);

    Department* departmentExist(const char* name) const;
    bool doctorExist(const Doctor& doc) const;
    bool nurseExist(const char* name) const;


    void print() const; 
};

#endif
