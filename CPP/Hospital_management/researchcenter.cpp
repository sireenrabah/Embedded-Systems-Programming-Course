#include <iostream>
#include <string.h>
using namespace std;

#include "researchcenter.h"


ResearcherCenter:: ResearcherCenter(const char* name )
 : name (nullptr),researcherarr(nullptr), physicalNumOfResearchers(2), logicalNumOfResearchers(0) ///constrastor
   {
    cout << "Craeting Department: "<< name << "\n";
    setname(name);
    researcherarr=new Researcher*[physicalNumOfResearchers];
    for(int i=0;i<physicalNumOfResearchers;i++)
        {
            researcherarr[i]=nullptr;
        }

   }
    
bool ResearcherCenter:: setname(const char* name)
    {
        if (name == nullptr){
        return false;
        }  
        delete[]  this->name;   
        this->name = new char[strlen(name) + 1];
        strcpy(this->name , name); 
        return true;
    }



/*bool ResearcherCenter::assignDoctor( Researcher& researcher)
{
  
    if(logicalNumOfDoctor==physicalNumOfDoctor)
    {
        physicalNumOfDoctor*=2;
        Doctor** tmp=new Doctor*[physicalNumOfDoctor];
        for(int i=0;i<logicalNumOfDoctor;i++)//copy the old array
        {
            tmp[i]=Doctorarr[i];
        }
        delete []Doctorarr;
        Doctorarr=tmp;
    }
   
    Doctorarr[logicalNumOfDoctor]=&doctor;
    logicalNumOfDoctor++;
    return true;
}*/

bool ResearcherCenter:: researcherExist(const Researcher& r) const
{
    for(int i=0; i < logicalNumOfResearchers; i++)
    {
        if(researcherarr[i] != nullptr && researcherarr[i]->getid() == r.getid())
            return true;
    }
    return false;
}



bool ResearcherCenter:: assignResearcher(Researcher& r)
{
    if(researcherExist(r))
        return false;

    if(logicalNumOfResearchers == physicalNumOfResearchers)
    {
        physicalNumOfResearchers *= 2;
        Researcher** temp = new Researcher*[physicalNumOfResearchers];
        for(int i=0; i<logicalNumOfResearchers; i++)
            temp[i] = researcherarr[i];
        for(int i=logicalNumOfResearchers; i<physicalNumOfResearchers; i++)
            temp[i] = nullptr;

        delete[] researcherarr;
        researcherarr = temp;
    }

    researcherarr[logicalNumOfResearchers] = &r;
    logicalNumOfResearchers++;
    return true;


}

ostream& operator<<(std::ostream& os, const ResearcherCenter& rc)
{
    os<< "Researcher Center Details: \n ";
    os << "name: " << rc.getname() << "\n";
    os <<"Showing the list of Researcher that belongs to this Center:\n";
    os << "Number of Researchers in this Center: " << rc.getlogicalNumOfResearchers() << "\n";

    for (int i = 0; i <rc.getlogicalNumOfResearchers(); i++)
	{
		os << " Researcher #" << (i + 1) << "\n";
        if (rc.researcherarr[i]!=nullptr)
        {
            os << *rc.researcherarr[i]<<"\n";

        } 
        else
        {
            os << "(null)\n";

        }
	}
	return os;

}

ResearcherCenter::~ResearcherCenter() // des c'tor
{
    delete[] name;
    delete[] researcherarr;
}
