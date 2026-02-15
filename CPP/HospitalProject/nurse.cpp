#include "nurse.h"
#include "department.h"
#include <iostream>
using namespace std;

Nurse::Nurse(const char* name, int yearsOfExperience)
      :Employee(name), yearsOfExperience(yearsOfExperience), department(nullptr)
{
    if (this->yearsOfExperience < 0)
        this->yearsOfExperience = 0;
}

Nurse::Nurse(const Nurse& other)
    : Employee(other), yearsOfExperience(other.yearsOfExperience), department(nullptr) 
{
}

Nurse& Nurse::operator=(const Nurse& other)
{
    if (this == &other)
        return *this;

    Employee::operator=(other); 
    yearsOfExperience = other.yearsOfExperience;
    department = nullptr;   
    return *this;
}

bool Nurse::setYearsOfExperience(int years)
{
    if (years < 0)
        return false;
    yearsOfExperience = years;
    return true;
}

void Nurse::print() const
{
    cout << "Nurse | ";
    Employee::print(); 
    cout << " , Experience: " << yearsOfExperience;

    if (department)
        cout << " , Department: " << department->getName();

    cout << endl;
}
