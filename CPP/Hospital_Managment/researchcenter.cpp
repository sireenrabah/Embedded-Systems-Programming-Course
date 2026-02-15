#include <iostream>
#include <cstring>

#include "researchcenter.h"
using namespace std;

ResearcherCenter::ResearcherCenter(const char* name)
    : name(nullptr)
{
    std::cout << "Creating Researcher Center: " << (name ? name : "") << "\n";
    setname(name);
}

bool ResearcherCenter:: setname(const char* name)
    {
        if (name == nullptr){
        return false;
        }  
        delete[]  this->name;   
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        return true;
    }

bool ResearcherCenter::researcherExist(const Researcher& r) const
{
    for (auto res : researchers)
        if (res && res->getid() == r.getid())
            return true;

    return false;
}

bool ResearcherCenter::assignResearcher(Researcher& r)
{
    if (researcherExist(r))
        return false;

    researchers.push_back(&r);
    return true;
}

std::ostream& operator<<(std::ostream& os, const ResearcherCenter& rc)
{
    os << "Researcher Center Details:\n";
    os << "name: " << rc.getname() << "\n";
    os << "Showing the list of Researchers that belongs to this Center:\n";
    os << "Number of Researchers in this Center: " << rc.getNumResearchers() << "\n";

    int i = 1;
    for (auto res : rc.researchers)
    {
        os << " Researcher #" << i++ << "\n";
        if (res)
            os << *res << "\n";
        else
            os << "(null)\n";
    }
    return os;
}

ResearcherCenter::~ResearcherCenter() // destructor
{
    delete[] name;
}
