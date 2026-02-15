#include <iostream>
#include <cstring>

#include "department.h"
#include "doctor.h"
#include "nurse.h"
Department::Department(const char* name) : name(nullptr)
{
    std::cout << "Creating Department: " << (name ? name : "") << "\n";
    setname(name);
}

void Department::setname(const char* name)
{
    if (!name) return;

    delete[] this->name;
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
}

bool Department::assignDoctor(Doctor& doctor)
{
    for (auto d : doctors)
        if (d == &doctor) return false;

    doctors.push_back(&doctor);
    return true;
}

bool Department::assignNurse(Nurse& nurse)
{
    for (auto n : nurses)
        if (n == &nurse) return false;

    nurses.push_back(&nurse);
    return true;
}

std::ostream& operator<<(std::ostream& os, const Department& dep)
{
    os << "\n----- Department Details -----\n";
    os << "Department Name: " << dep.getname() << "\n";

    os << "\nDoctors:\n";
    os << "Number of Doctors: " << dep.getNumDoctors() << "\n";
    for (auto d : dep.doctors)
        os << *d << "\n";

    os << "\nNurses:\n";
    os << "Number of Nurses: " << dep.getNumNurses() << "\n";
    for (auto n : dep.nurses)
        os << *n << "\n";
    os << "-------------------------------\n";
    return os;
}

bool Department::removeDoctor(Doctor& oldDoctor)
{
    for (auto it = doctors.begin(); it != doctors.end(); ++it)
        if (*it == &oldDoctor)
        {
            doctors.erase(it);
            return true;
        }
    return false;
}

bool Department::removeNurse(Nurse& oldNurse)
{
    for (auto it = nurses.begin(); it != nurses.end(); ++it)
        if (*it == &oldNurse)
        {
            nurses.erase(it);
            return true;
        }
    return false;
}

Department:: ~Department()//disconstrastor
{
    delete[] name;
}