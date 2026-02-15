#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

#include "patient.h"
   
Patient::Patient(const char* name, int id, const char* gender, int birthyear)
    : Person(name, id), gender(nullptr), birthyear(birthyear) //ctor
{
    cout<<"In Patient::Patient \n";
    setgender(gender);
}

Patient:: Patient(const Patient& other)
: Person(other), gender(nullptr), birthyear(other.birthyear)
{
    cout<<"In Patient::Patient (copy)\n";
    setgender(other.gender);
}

Patient& Patient::operator=(const Patient& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        setgender(other.gender);
        birthyear = other.birthyear;
    }
    return *this;
}

Patient::Patient(Patient&& other) noexcept
    : Person(std::move(other)), gender(other.gender), birthyear(other.birthyear)
{
    other.gender = nullptr;
    other.birthyear = 0;
}

Patient& Patient::operator=(Patient&& other) noexcept
{
    if (this != &other)
    {
        Person::operator=(std::move(other));

        delete[] gender;
        gender = other.gender;
        birthyear = other.birthyear;

        other.gender = nullptr;
        other.birthyear = 0;
    }
    return *this;
}

bool Patient::setgender(const char* gender)
{
    if (!gender) return false;

    char* tmp = new char[std::strlen(gender) + 1];
    std::strcpy(tmp, gender);

    delete[] this->gender;
    this->gender = tmp;
    return true;
}

bool  Patient:: setbirthyear(const int birthyear)
{
    this->birthyear=birthyear;
    return true;
}

std::ostream& operator<< (std::ostream& os,const Patient& p)
{
    os << "The Patient Details: \n";
	os << "name: " << p.getname() << "\n";
	os << "Patient Id: " << p.getid() << "\n";
    os << "gender: " << p.getgender() << "\n";
	os << "birthyear : " << p.getbirthyear() << "\n";
	return os;
}

Patient:: ~Patient()  //destructor
{
    cout<<"In Patient::~Patient \n";
    delete[] gender; 
}
