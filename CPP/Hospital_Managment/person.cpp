
#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

#include "person.h"
   
Person:: Person (const char* name ,const int id) : name(nullptr),id(id)///constrastor
{
    cout<<"In Person::Person \n";
    setname(name);
}

Person::Person(const Person& other)
    : name(nullptr), id(other.id)
{
    setname(other.name);
}

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        setname(other.name);
        id = other.id;
    }
    return *this;
}

Person::Person(Person&& other) noexcept
    : name(other.name), id(other.id)
{
    other.name = nullptr;
    other.id = 0;
}

Person& Person::operator=(Person&& other) noexcept
{
    if (this != &other)
    {
        delete[] name;
        name = other.name;
        id = other.id;

        other.name = nullptr;
        other.id = 0;
    }
    return *this;
}

bool Person::setname(const char* newName)
{
    if (!newName) return false;

    char* tmp = new char[strlen(newName) + 1];
    strcpy(tmp, newName);

    delete[] name;
    name = tmp;
    return true;
}

ostream& operator<< (ostream& os,const Person& p)
{
    os << "The Person Details: \n";
	os << "name: " << p.getname() << "\n";
	os << "Person Id: " << p.getid() << "\n";
	return os;
}

Person:: ~Person()//disconstrastor
{
    cout<<"In Person::~Person \n";
    delete[] name; 
}
