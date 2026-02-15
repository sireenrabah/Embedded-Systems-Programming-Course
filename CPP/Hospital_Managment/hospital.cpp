
#include <iostream>
#include <cstring>

using namespace std;

#include "hospital.h"

Hospital::Hospital(const char* hospitalname)
    : hospitalname(nullptr), researcherCenter(nullptr)
{
    setHospitalname(hospitalname);
    researcherCenter = new ResearcherCenter(this->hospitalname);
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
    for (auto dep : departments)
        if (strcmp(dep->getname(), name) == 0)
            return dep;

    return nullptr;
}

bool Hospital::addDepartment(const char* name)
{
    if (!name) return false;
    if (departmentExist(name)) return false;

    departments.push_back(new Department(name));
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
    for (auto emp : employees)
        if (emp->getid() == Emp.getid())
            return true;

    return false;
}
    bool Hospital::addEmployee(Employee &Emp )
    {
        if (EmployeeExist(Emp))
        {
            return false;
        }
            
        employees.push_back(Emp.clone());
        return true;

    }

Hospital:: ~Hospital()  //destructor
{
    delete []hospitalname;
    delete researcherCenter;

    for (auto dep : departments)
        delete dep;
    for (auto emp : employees)
        delete emp;
     
}

std::ostream& operator<<(std::ostream& os, const Hospital& h)
{
    os << "\n====== Hospital Details ======\n";
    os << "Hospital Name: " << h.getHospitalname() << "\n";

    os << "\nDepartments in Hospital:\n";
    os << "Number of Departments: " << h.getNumOfDepartments() << "\n\n";

    for (auto dep : h.getDepartments())
        os << *dep << "\n";

    os << "\nAll Employees in Hospital:\n";
    os << "Number of Employees: " << h.getNumOfEmployees() << "\n\n";

    for (auto emp : h.getEmployees())
        os << *emp << "\n";

    os << "==============================\n";
    return os;
}

int Hospital::getNumOfDepartments() const
{
    return (int)departments.size();
}

int Hospital::getNumOfEmployees() const
{
    return (int)employees.size();
}

const std::vector<Department*>& Hospital::getDepartments() const
{
    return departments;
}

const std::vector<Employee*>& Hospital::getEmployees() const
{
    return employees;
}
