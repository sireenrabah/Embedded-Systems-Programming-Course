#include "department.h"
#include "doctor.h"
#include "nurse.h"
#include <cstring>
#include <iostream>
using namespace std;

Department::Department(const char* name)
    : name(nullptr),
      arrDoctor(nullptr), physicalNumOfDoc(2), logicalNumOfDoc(0),
      arrNurse(nullptr), physicalNumOfNurse(2), logicalNumOfNurse(0)
{
    cout << "New Department: " << (name ? name : "") << endl;
    setName(name);

    arrDoctor = new Doctor*[physicalNumOfDoc];
    for (int i = 0; i < physicalNumOfDoc; i++)
    {
        arrDoctor[i] = nullptr;
    }

    arrNurse = new Nurse*[physicalNumOfNurse];
    for (int i = 0; i < physicalNumOfNurse; i++)
    {
        arrNurse[i] = nullptr;
    }
}

Department::~Department()
{
    delete[] name;
    delete[] arrDoctor;
    delete[] arrNurse; 
}

bool Department::setName(const char* name)
{
    if (!name) return false;

    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    return true;
}

bool Department::doctorExists(const Doctor* doctor) const
{
    if (!doctor) return false;

    for (int i = 0; i < logicalNumOfDoc; i++)
    {
        if (arrDoctor[i] == doctor)
            return true;
    }
    return false;
}

bool Department::nurseExists(const Nurse* nurse) const
{
    if (!nurse) return false;
    for (int i = 0; i < logicalNumOfNurse; i++)
        if (arrNurse[i] == nurse)
            return true;
    return false;
}

bool Department::assignDoctor(Doctor* doctor)
{
    if (!doctor) return false;
    if (doctorExists(doctor)) return false;

    if (logicalNumOfDoc == physicalNumOfDoc)
    {
        physicalNumOfDoc *= 2;
        Doctor** tmp = new Doctor*[physicalNumOfDoc];

        for (int i = 0; i < logicalNumOfDoc; i++)
            tmp[i] = arrDoctor[i];
        for (int i = logicalNumOfDoc; i < physicalNumOfDoc; i++)
            tmp[i] = nullptr;

        delete[] arrDoctor;
        arrDoctor = tmp;
    }

    arrDoctor[logicalNumOfDoc] = doctor;
    logicalNumOfDoc++;
    return true;
}

bool Department::assignNurse(Nurse* nurse)
{
    if (!nurse) return false;
    if (nurseExists(nurse)) return false;

    if (logicalNumOfNurse == physicalNumOfNurse)
    {
        physicalNumOfNurse *= 2;
        Nurse** tmp = new Nurse*[physicalNumOfNurse];

        for (int i = 0; i < logicalNumOfNurse; i++) tmp[i] = arrNurse[i];
        for (int i = logicalNumOfNurse; i < physicalNumOfNurse; i++) tmp[i] = nullptr;

        delete[] arrNurse;
        arrNurse = tmp;
    }

    arrNurse[logicalNumOfNurse] = nurse;
    logicalNumOfNurse++;
    return true;
}

void Department::print() const
{
    cout << "Department: " << (name ? name : "") << endl;

    cout << "Doctors: " << endl;
    for (int i = 0; i < logicalNumOfDoc; i++)
        if (arrDoctor[i]) arrDoctor[i]->print();

    cout << "Nurses: " << endl;
    for (int i = 0; i < logicalNumOfNurse; i++)
        if (arrNurse[i]) arrNurse[i]->print();
}