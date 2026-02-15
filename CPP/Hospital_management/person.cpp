
#include <iostream>
#include <string.h>
using namespace std;

#include "person.h"
   
   
   
   
Person:: Person (const char* name ,const int id) : name(nullptr),id(id)///constrastor
{
    cout<<"In Person::Person \n";
    setname(name);
}

Person:: Person(const Person& other) : name (nullptr), id(other.id)
{
    cout<<"In Person::Person (copy)\n";
    *this=other;
}

const Person& Person :: operator=(const Person& other) 
{
    cout<<"In Person::Person (operator=)\n";
     if(this!= &other){

        delete[] this->name;  
        setname(other.name);
        id = other.id;
    }
    return *this;
}

Person:: Person( Person&& other) : name(other.name), id(other.id)
{
    other.name = nullptr;
    other.id = 0; 
    
}

Person& Person:: operator=( Person&& other)
   {
    if(this!= &other){
        std:: swap(name,other.name);
        std:: swap(id,other.id);
        
    }
    return *this;

   }

bool Person:: setname(const char* name)
{
    if (name == nullptr){
        return false;
        }  
        delete[] this->name;   
        this->name = new char[strlen(name) + 1];
        strcpy( this->name ,name); 
        return true; 

}

ostream& operator<< (ostream& os,const Person& p)
{
    os << "The Person Details: \n";
	os << "name: " << p.getname() << "\n";
	os << "Doctor Id: " << p.getid() << "\n";
	return os;
}

Person:: ~Person()//disconstrastor
{
    cout<<"In Person::~Person \n";
    delete[] name; 
}
