#include "employee.h"
#include <iostream>
using namespace std;

int Employee::nextSerial = 1;

Employee::Employee(const char* name)
    : Person(name)
{
    serialNumber = nextSerial++;
}

Employee::Employee(const Employee& other): Person(other), serialNumber(other.serialNumber)
{
}

Employee& Employee::operator=(const Employee& other)
{
    if (this == &other)
        return *this;

    Person::operator=(other);
    serialNumber = other.serialNumber;
    return *this;
}

void Employee::print() const
{
    cout << "Employee | " ;
    Person::print();
}
