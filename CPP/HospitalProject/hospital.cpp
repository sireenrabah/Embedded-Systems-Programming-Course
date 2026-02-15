#include "hospital.h"
#include <cstring>
#include <iostream>
using namespace std;

Hospital::Hospital(const char* name)
    : name(nullptr),
      physicalNumOfDoc(2),
      physicalNumOfDep(2),
      physicalNumOfNurses(2),
      logicalNumOfDoc(0),
      logicalNumOfDep(0),
      logicalNumOfNurses(0),
      doctors(nullptr),
      departments(nullptr),
      nurses(nullptr)
{
    cout << "Creating Hospital " << (name ? name : "") << endl;
    setName(name);

    departments = new Department*[physicalNumOfDep];
    doctors     = new Doctor*[physicalNumOfDoc];
    nurses = new Nurse*[physicalNumOfNurses];

    for (int i = 0; i < physicalNumOfDep; i++) departments[i] = nullptr;
    for (int i = 0; i < physicalNumOfDoc; i++) doctors[i] = nullptr;
    for (int i = 0; i < physicalNumOfNurses; i++) nurses[i] = nullptr;
}

Hospital::~Hospital()
{
    delete[] name;

    for (int i = 0; i < logicalNumOfDep; i++)
        delete departments[i];
    delete[] departments;

    for (int i = 0; i < logicalNumOfDoc; i++)
        delete doctors[i];
    delete[] doctors;

    for (int i = 0; i < logicalNumOfNurses; i++)
        delete nurses[i];
    delete[] nurses;
}

bool Hospital::setName(const char* name)
{
    if (!name)
        return false;

    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    return true;
}

Department* Hospital::departmentExist(const char* name) const
{
    if (!name) return nullptr;

    for (int i = 0; i < logicalNumOfDep; i++)
    {
        if (departments[i] && strcmp(departments[i]->getName(), name) == 0)
            return departments[i];
    }
    return nullptr;
}

bool Hospital::doctorExist(const Doctor& doc) const
{
    for (int i = 0; i < logicalNumOfDoc; i++)
    {
        if (strcmp(doctors[i]->getName(), doc.getName()) == 0 &&
            strcmp(doctors[i]->getSpecialization(), doc.getSpecialization()) == 0)
        {
            return true;
        }
    }
    return false;
}

bool Hospital::nurseExist(const char* name) const
{
    if (!name) return false;

    for (int i = 0; i < logicalNumOfNurses; i++)
    {
        if (strcmp(nurses[i]->getName(), name) == 0)
            return true;
    }
    return false;
}

bool Hospital::addDepartment(const char* name)
{
    if (!name) return false;
    if (departmentExist(name)) return false;

    if (logicalNumOfDep == physicalNumOfDep)
    {
        physicalNumOfDep *= 2;
        Department** tmp = new Department*[physicalNumOfDep];

        for (int i = 0; i < logicalNumOfDep; i++)
            tmp[i] = departments[i];
        for (int i = logicalNumOfDep; i < physicalNumOfDep; i++)
            tmp[i] = nullptr;

        delete[] departments;
        departments = tmp;
    }

    
    departments[logicalNumOfDep] = new Department(name);
    logicalNumOfDep++;
    return true;
}

bool Hospital::addDoctor(const Doctor& doctor, const char* departmentName)
{
    if (!departmentName) return false;
    if (doctorExist(doctor)) return false;

    Department* dept = departmentExist(departmentName);
    if (!dept)
    {
        cout << "This department does not exist, can't add this doctor" << endl;
        return false;
    }

    if (logicalNumOfDoc == physicalNumOfDoc)
    {
        physicalNumOfDoc *= 2;
        Doctor** tmp = new Doctor*[physicalNumOfDoc];

        for (int i = 0; i < logicalNumOfDoc; i++)
            tmp[i] = doctors[i];
        for (int i = logicalNumOfDoc; i < physicalNumOfDoc; i++)
            tmp[i] = nullptr;

        delete[] doctors;
        doctors = tmp;
    }

    doctors[logicalNumOfDoc] = new Doctor(doctor); 
    dept->assignDoctor(doctors[logicalNumOfDoc]);
    doctors[logicalNumOfDoc]->setDepartment(dept);
    logicalNumOfDoc++;
    return true;
}

bool Hospital::addNurse(const char* name, int yearsOfExperience, const char* departmentName)
{
    if (!name || !departmentName)
        return false;

    if (nurseExist(name))
        return false;

    Department* dept = departmentExist(departmentName);
    if (!dept)
    {
        cout << "this department is not exist , can't add this nurse" << endl;
        return false;
    }

    if (logicalNumOfNurses == physicalNumOfNurses)
    {
        physicalNumOfNurses *= 2;
        Nurse** tmp = new Nurse*[physicalNumOfNurses];

        for (int i = 0; i < logicalNumOfNurses; i++)
            tmp[i] = nurses[i];
        for (int i = logicalNumOfNurses; i < physicalNumOfNurses; i++)
            tmp[i] = nullptr;

        delete[] nurses;
        nurses = tmp;
    }

    nurses[logicalNumOfNurses] = new Nurse(name, yearsOfExperience);


    nurses[logicalNumOfNurses]->setDepartment(dept);

    dept->assignNurse(nurses[logicalNumOfNurses]);

    logicalNumOfNurses++;
    return true;
}


void Hospital::print() const
{
    cout << "Hospital: " << name << endl;
    cout << "Departments: " << logicalNumOfDep << endl;

    for (int i = 0; i < logicalNumOfDep; i++)
    {
        if (departments[i])
        {
            departments[i]->print();
            cout << "----" << endl;
        }
    }
}
