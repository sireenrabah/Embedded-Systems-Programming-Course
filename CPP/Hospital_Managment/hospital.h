#ifndef __HOSPITAL_H__
#define __HOSPITAL_H__

#include <vector>

#include "doctor.h"
#include "department.h"
#include "employee.h"
#include "researcher.h"
#include "researchcenter.h"


class Hospital
{

private:
    char* hospitalname;
    
    std::vector<Department*> departments;
    std::vector<Employee*> employees;

    ResearcherCenter* researcherCenter;

public:

    Hospital (const char* hospitalname );   ///constructor
    Hospital(const Hospital&)=delete;   //copy constrastor
    Hospital& operator=(const Hospital&)=delete;
    ~Hospital();   //destructor

    const char* getHospitalname()   const {return hospitalname;}

    int getNumOfDepartments() const;
    int getNumOfEmployees() const;
    const std::vector<Department*>& getDepartments() const;
    const std::vector<Employee*>& getEmployees() const;


    bool setHospitalname(const char* hospitalname);

    Department* departmentExist(const char* name) const;
    bool addDepartment(const char* name );

    bool addDoctortodepartment(Doctor &Doc , const char* departmentname);
    bool addResearchertoResearchercenter(Researcher & Res );
    bool EmployeeExist(const Employee &Emp) const;
    bool addEmployee(Employee &Emp );

    friend std::ostream& operator<<(std::ostream& os, const Hospital& h);

    
};

#endif
