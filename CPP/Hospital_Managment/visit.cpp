#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

#include "visit.h"
   
Visit::Visit(const char* visitDay, const char* purposeofvisit)
    : visitDay(nullptr), purposeofvisit(nullptr)
{
    setvisitDay(visitDay);
    setpurposeofvisit(purposeofvisit);
}


Visit::Visit(const Visit& other) noexcept
    : visitDay(nullptr), purposeofvisit(nullptr)
{
    setvisitDay(other.visitDay);
    setpurposeofvisit(other.purposeofvisit);
}

Visit& Visit::operator=(Visit&& other) noexcept
{
    if (this != &other)
    {
        delete[] visitDay;
        delete[] purposeofvisit;

        visitDay = other.visitDay;
        purposeofvisit = other.purposeofvisit;

        other.visitDay = nullptr;
        other.purposeofvisit = nullptr;
    }
    return *this;
}

bool Visit:: setvisitDay(const char* visitDay)
{
    if (visitDay == nullptr){
        return false;
        }  
        char* tmp = new char[std::strlen(visitDay) + 1];
        std::strcpy(tmp, visitDay);

        delete[] this->visitDay;
        this->visitDay = tmp;
 
        return true; 

}

bool Visit:: setpurposeofvisit(const char* purposeofvisit)
{
    if (purposeofvisit == nullptr){
        return false;
        }  
        char* tmp = new char[std::strlen(purposeofvisit) + 1];
        std::strcpy(tmp, purposeofvisit);

        delete[] this->purposeofvisit;
        this->purposeofvisit = tmp;

        return true; 

}




std::ostream& operator<<(std::ostream& os, const Visit& v)
{
    os << "The Visit Details: \n";
	os << "visitDay: " << v.getvisitDay() << "\n";
	os << "purposeofvisit : " << v.getpurposeofvisit() << "\n";

	return os;
}

Visit:: ~Visit() //destructor
{
    cout <<"In Visit::~Visit \n";
    delete[] purposeofvisit;
    delete[] visitDay; 
}
