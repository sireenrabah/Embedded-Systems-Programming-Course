#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
using namespace std;

class Person
{

private:
    char* name;
    int id;

    
    
public:

    Person (const char* name ,const int id);///constrastor
    Person(const Person& other);//copy constrastor
    Person( Person&& other);
    const Person& operator=(const Person& other);
    Person& operator=( Person&& other);
    ~Person();   //disconstrastor

    friend std::ostream& operator<< (std::ostream& os,const Person& p);

    const char* getname()   const {return name;}
    int getid()      const {return id;}

    bool setname(const char* name);





    
};






#endif
