
#include <iostream>
#include <string.h>
using namespace std;

#include "hospital.h"




    Hospital:: Hospital(const char* hospitalname) : hospitalname(nullptr),department(nullptr),employee(nullptr),researcherCenter(nullptr),
    physicalNumOfDepartment(2), logicalNumOfDepartment(0),physicalNumOfEmployee(2), logicalNumOfEmployee(0)
    {
        setHospitalname(hospitalname);
        department = new Department*[physicalNumOfDepartment];
        for(int i=0;i<physicalNumOfDepartment;i++)
        {
            department[i]=nullptr;
        }
        researcherCenter = new ResearcherCenter(this->hospitalname);

        employee= new Employee*[physicalNumOfEmployee];
        for(int i=0;i<physicalNumOfEmployee;i++)
        {
            employee[i]=nullptr;
        }

    }


    bool Hospital:: setHospitalname(const char* hospitalname)
    {
        if (hospitalname == nullptr){
        return false;
        }  
        delete[]this-> hospitalname;   
        this->hospitalname = new char[strlen(hospitalname) + 1];
        strcpy(this->hospitalname , hospitalname); 
        return true;
    }

    Department* Hospital::departmentExist(const char* name) const
    {
        for (int i = 0; i < logicalNumOfDepartment; i++)
            if (strcmp(department[i]->getname(), name) == 0)
            {
                return department[i];
            }
        return nullptr;
    }


    bool Hospital::addDepartment(const char* name)
    {
        if(name==nullptr)
        {
            return false;
        }
        if (departmentExist(name))
            return false;
            
        if (logicalNumOfDepartment == physicalNumOfDepartment)
        {
            physicalNumOfDepartment *= 2;
            Department** temp = new Department*[physicalNumOfDepartment];
            for (int i=0 ; i < logicalNumOfDepartment ; i++)
               {
                 temp[i] = department[i];
               }
            
            for (int i = logicalNumOfDepartment; i < physicalNumOfDepartment; i++)
                temp[i] = nullptr;

            delete []department;
            department = temp;
        }
        department[logicalNumOfDepartment] = new Department(name);
        logicalNumOfDepartment++;
        return true;

    }



bool Hospital::addDoctortodepartment(Doctor& Doc, const char* departmentname)
{
    if (!departmentname)
        return false;

    if (!EmployeeExist(Doc))
        return false;

    Department* deprt = departmentExist(departmentname);
    if (deprt == nullptr)
        return false;

    if (!deprt->assignDoctor(Doc))
        return false;

    Doc.setDepartment(deprt);
    return true;
}

bool Hospital::addResearchertoResearchercenter(Researcher& Res)
{
    if (!EmployeeExist(Res))
        return false;

    if (researcherCenter == nullptr)
        researcherCenter = new ResearcherCenter(this->hospitalname);

    return researcherCenter->assignResearcher(Res);
}


bool Hospital::EmployeeExist(const Employee &Emp) const
{
    for (int i = 0; i < logicalNumOfEmployee; i++)
        if (employee[i]->getid() == Emp.getid())
        {
            return true;
        }
    return false;
}


    bool Hospital::addEmployee(Employee &Emp )
    {
        if (EmployeeExist(Emp))
        {
            return false;
        }
            
        if (logicalNumOfEmployee == physicalNumOfEmployee)
        {
            physicalNumOfEmployee *= 2;
            Employee** temp = new Employee*[physicalNumOfEmployee];
            for (int i=0 ; i < logicalNumOfEmployee ; i++) 
            {
                temp[i] = employee[i];
            }
            delete []employee;
            employee = temp;
        }

        employee[logicalNumOfEmployee]=Emp.clone();
        logicalNumOfEmployee++;
        return true;

    }



Hospital:: ~Hospital()  //disconstrastor
{
    delete []hospitalname;
    delete researcherCenter;

    for (int i = 0; i < logicalNumOfDepartment; i++)
        {
            delete department[i];
        }
    delete[] department;

        /*  for (int i = 0; i < logicalNumOfDoctor; i++)
        {
            delete doctor[i];
        }
        delete[] doctor; */

    for (int i = 0; i < logicalNumOfEmployee; i++)
        {
            delete employee[i];
        }
    delete[] employee;
     
}

std::ostream& operator<<(std::ostream& os, const Hospital& h)
{
    os << "\n====== Hospital Details ======\n";
    os << "Hospital Name: " << h.getHospitalname() << "\n";

    os << "\nDepartments in Hospital:\n";
    os << "Number of Departments: " << h.getlogicalNumofDepartment() << "\n\n";

    for (int i = 0; i < h.getlogicalNumofDepartment(); i++)
    {
        if (h.department[i] != nullptr)
        {
            os << *h.department[i] << "\n";
        }
    }

    os << "\nAll Employees in Hospital:\n";
    for (int i = 0; i < h.logicalNumOfEmployee; i++)
    {
        if (h.employee[i] != nullptr)
        {
            os << *h.employee[i] << "\n";
        }
    }

    os << "==============================\n";

    return os;
}
