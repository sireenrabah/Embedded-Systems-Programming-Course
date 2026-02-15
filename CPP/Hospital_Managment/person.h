#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>

class Person
{

private:
    char* name;
    int id;

public:

    Person (const char* name ,const int id);  ///constructor
    Person(const Person& other); //copy constructor
    Person(Person&& other) noexcept; //כדי שוקטור יזיז ולא יעתיקק 
    Person& operator=(Person&& other) noexcept; 
    Person& operator=(const Person& other);
    ~Person();   //destructor

    friend std::ostream& operator<< (std::ostream& os,const Person& p);

    const char* getname()   const {return name;}
    int getid()      const {return id;}

    bool setname(const char* name);





    
};






#endif
