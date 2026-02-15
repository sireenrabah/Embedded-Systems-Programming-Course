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

    Department** department;
    int physicalNumOfDepartment, logicalNumOfDepartment;    
    Employee** employee;
    int physicalNumOfEmployee, logicalNumOfEmployee;
    
    ResearcherCenter* researcherCenter;



    
public:

    Hospital (const char* hospitalname );///constrastor
    Hospital(const Hospital&)=delete;//copy constrastor
    Hospital& operator=(const Hospital&)=delete;
    ~Hospital();//disconstrastor

    const char* getHospitalname()   const {return hospitalname;}
    int getphysicalNumofDepartment() const{return physicalNumOfDepartment;}
    int getlogicalNumofDepartment() const{return logicalNumOfDepartment;}


    bool setHospitalname(const char* hospitalname);
    /*int setphysicalNumofDoctor();
    int setphysicalNumofDepartment() ;
    int setlogicalNumofDoctor() const ;
    int setlogicalNumofDepartment() const;*/
 

    Department** getDepartment() const {return department;}

    Department* departmentExist(const char* name) const;
    bool addDepartment(const char* name );

   // bool doctorExist(const Doctor &Doc) const;
    bool addDoctortodepartment(Doctor &Doc , const char* departmentname);
    bool addResearchertoResearchercenter(Researcher & Res );
    bool EmployeeExist(const Employee &Emp) const;
    bool addEmployee(Employee &Emp );

    friend std::ostream& operator<<(std::ostream& os, const Hospital& h);

    
};

#endif
