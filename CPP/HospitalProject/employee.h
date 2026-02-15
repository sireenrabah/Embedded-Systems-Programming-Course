#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "person.h"

class Employee : public Person
{
protected:
    static int    nextSerial;
    int           serialNumber;

public:
    Employee(const char* name);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    virtual      ~Employee() = default;

    int          getSerialNumber() const      { return serialNumber; }

    virtual void print() const override;
};

#endif
