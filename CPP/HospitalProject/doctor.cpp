#include "doctor.h"
#include "department.h"
#include <cstring>
#include <iostream>
using namespace std;

Doctor::Doctor(const char* name, const char* specialization)
       :Employee(name),
      specialization(nullptr),
      department(nullptr)
{
    if (!specialization) specialization = "";
    this->specialization = new char[strlen(specialization) + 1];
    strcpy(this->specialization, specialization);
}

Doctor::Doctor(const Doctor& other)
       :Employee(other), specialization(nullptr), department(nullptr)        
{
    this->specialization = new char[strlen(other.specialization) + 1];
    strcpy(this->specialization, other.specialization);
}

Doctor& Doctor::operator=(const Doctor& other)
{
    if (this == &other)
        return *this;

    Employee::operator=(other);  // copyy name and serila number

    delete[] specialization;
    specialization = new char[strlen(other.specialization) + 1];
    strcpy(specialization, other.specialization);

    department = nullptr;    
    return *this;
}

Doctor::~Doctor()
{
    delete[] specialization;
}

void Doctor::print() const
{
    cout << "Doctor |" ;
    Person::print();             // print namee
    cout << " , Specialization: " << specialization;

    if (department)
        cout << " , Department: " << department->getName();

    cout << endl;
}
