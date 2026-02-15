
#include <iostream>
#include <string.h>
using namespace std;

#include "employee.h"
   
int Employee::nextSerial = 1;  

Employee::Employee (const char* name,const int id) :Person(name,id)
{
   serialnum = nextSerial++;   
} 

std::ostream& operator<< (std::ostream& os,const Employee& e)
{
    os << "Employee Details: \n";
	os << "name: " << e.getname() << "\n";
	os << "Doctor Id: " << e.getid() << "\n";
    os << "serialnum: " << e.getserialnum() << "\n";
	return os;
}


