#include <iostream>
#include <string.h>
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

const Patient& Patient::operator=(const Patient& other) 
{
    cout<<"In Patient::Patient (operator=)\n";

    if(this== &other)
    {
        return *this;
    }
    Person::operator=(other);
    setgender(other.gender);
    birthyear = other.birthyear;

    return *this;
}

Patient::Patient(Patient&& other)
    : Person(std::move(other)), gender(other.gender), birthyear(other.birthyear)
{
    other.gender = nullptr;
}


Patient& Patient:: operator=( Patient&& other)
   {
    if(this!= &other){
        std:: swap(birthyear,other.birthyear);
        std:: swap(gender,other.gender);
        
    }
    return *this;

   }

bool Patient:: setgender(const char* gender)
{
    if (gender == nullptr){
        return false;
        }  
        delete[] this->gender;   
        this->gender = new char[strlen(gender) + 1];
        strcpy( this->gender ,gender); 
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
	os << "Doctor Id: " << p.getid() << "\n";
    os << "gender: " << p.getgender() << "\n";
	os << "birthyear : " << p.getbirthyear() << "\n";
	return os;
}

Patient:: ~Patient()//disconstrastor
{
    cout<<"In Patient::~Patient \n";
    delete[] gender; 
}
