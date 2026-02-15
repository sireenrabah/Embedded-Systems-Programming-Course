#include <iostream>
using namespace std;
#include <cstring>

#include "visit.h"
   
Visit::Visit(const char* visitDay, const char* purposeofvisit)
    : visitDay(nullptr), purposeofvisit(nullptr)
{
    setvisitDay(visitDay);
    setpurposeofvisit(purposeofvisit);
}


Visit::Visit(const Visit& other)
    : visitDay(nullptr), purposeofvisit(nullptr)
{
    setvisitDay(other.visitDay);
    setpurposeofvisit(other.purposeofvisit);
}


const Visit& Visit::operator=(const Visit& other)
{
    if (this == &other)
        return *this;

    setvisitDay(other.visitDay);
    setpurposeofvisit(other.purposeofvisit);

    return *this;
}


Visit::Visit(Visit&& other)
    : visitDay(other.visitDay), purposeofvisit(other.purposeofvisit)
{
    other.visitDay = nullptr;
    other.purposeofvisit = nullptr;
}


Visit& Visit:: operator=( Visit&& other)
   {
    if(this!= &other){
        std:: swap(visitDay,other.visitDay);
        std:: swap(purposeofvisit,other.purposeofvisit);
        
    }
    return *this;

   }

bool Visit:: setvisitDay(const char* visitDay)
{
    if (visitDay == nullptr){
        return false;
        }  
        delete[] this->visitDay;   
        this->visitDay = new char[strlen(visitDay) + 1];
        strcpy( this->visitDay ,visitDay); 
        return true; 

}

bool Visit:: setpurposeofvisit(const char* purposeofvisit)
{
    if (purposeofvisit == nullptr){
        return false;
        }  
        delete[] this->purposeofvisit;   
        this->purposeofvisit = new char[strlen(purposeofvisit) + 1];
        strcpy( this->purposeofvisit ,purposeofvisit); 
        return true; 

}




std::ostream& operator<<(std::ostream& os, const Visit& v)
{
    os << "The Visit Details: \n";
	os << "visitDay: " << v.getvisitDay() << "\n";
	os << "purposeofvisit : " << v.getpurposeofvisit() << "\n";

	return os;
}

Visit:: ~Visit() //disconstrastor
{
    cout <<"In Patient::~Patient \n";
    delete[] purposeofvisit;
    delete[] visitDay; 
}
