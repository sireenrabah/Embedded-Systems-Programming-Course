#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include "person.h"

class Employee : public Person
{
protected:
    static int nextSerial; 
    int serialnum;
    Employee(const Employee& )=default;  //copy constrastor
    Employee& operator=(const Employee& ) = default;
    
public:
    Employee (const char* name,const int id);  ///constrastor
    virtual ~Employee() = default;
    
    int getserialnum()      const {return serialnum;}

    virtual Employee* clone() const =0;
    friend std::ostream& operator<< (std::ostream& os,const Employee& e);
    
};






#endif
