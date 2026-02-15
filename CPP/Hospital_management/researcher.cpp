
#include <iostream>
#include <string.h>
using namespace std;

#include "researcher.h"
   
Researcher::Researcher(const char* name, const int id)
    : Employee(name, id), arrarticles(nullptr), logicalNumOfArticles(0), physicalNumOfArticles(2)
{
    arrarticles = new Articles*[physicalNumOfArticles];
    for (int i = 0; i < physicalNumOfArticles; i++)
        arrarticles[i] = nullptr;
}


Researcher::Researcher(const Researcher& other)
    : Employee(other), arrarticles(nullptr),
      logicalNumOfArticles(other.logicalNumOfArticles),
      physicalNumOfArticles(other.physicalNumOfArticles)
{
    cout<<"In Researcher::Researcher (copy)\n";
    this->arrarticles=nullptr;
    *this=other;
}

const Researcher& Researcher::operator=(const Researcher& other)
{
    if (this == &other)
        return *this;

    for (int i = 0; i < logicalNumOfArticles; i++)
        delete arrarticles[i];
    delete[] arrarticles;

    physicalNumOfArticles = other.physicalNumOfArticles;
    logicalNumOfArticles = other.logicalNumOfArticles;

    arrarticles = new Articles*[physicalNumOfArticles];
    for (int i = 0; i < physicalNumOfArticles; i++)
        arrarticles[i] = nullptr;

    for (int i = 0; i < logicalNumOfArticles; i++)
        arrarticles[i] = new Articles(*other.arrarticles[i]);

    return *this;
}

Researcher& Researcher::operator=(Researcher&& other)
{
    if (this == &other)
        return *this;

    std::swap(arrarticles, other.arrarticles);
    std::swap(logicalNumOfArticles, other.logicalNumOfArticles);
    std::swap(physicalNumOfArticles, other.physicalNumOfArticles);

    return *this;
}

/*
Researcher& Researcher:: operator=( Researcher&& other)
   {
    if(this!= &other){
    
        std:: swap(arrarticles,other.arrarticles);
        }

    
    return *this;

   }
*/

/*bool Researcher:: setmaxArticles(int maxArticles)
{
    if(maxArticles<0)
    {
        return false;
    }
  this->maxArticles=maxArticles;
  return true;
}*/

Researcher:: ~Researcher()//disconstrastor
{
    cout<<"In Person::~Person \n";
    for (int i = 0; i < logicalNumOfArticles; i++)
        delete arrarticles[i];

    delete[] arrarticles;
}

/*
bool Researcher::ResearcherExist(const Researcher &Res) const
    {
        for (int i = 0; i < logicalNumOfArticles; i++)
            if (strcmp(Researcher[i]->getarticleName(),Res.getarticleName())==0) 
            {
                return true;
            }
        return false;
    }

     
bool Researcher:: addResearcher( Articles& articles)
{
   if (ResearcherExist(Emp))
        {
            return false;
        }
           
    if(logicalNumOfArticles==physicalNumOfArticles)
    {
        physicalNumOfArticles*=2;
        Articles** tmp=new Articles*[physicalNumOfArticles];
        for(int i=0;i<logicalNumOfArticles;i++)//copy the old array
        {
            tmp[i]=arrArticles[i];
        }
        delete []arrArticles;
        arrArticles=tmp;
    }
   
    arrArticles[logicalNumOfArticles]=&articles;
    logicalNumOfArticles++;
    return true;
}
*/

std::ostream& operator<< (std::ostream& os,const Researcher& r)
{
    os << "The Researcher Details: \n";
    os << "Researcher Name: " << r.getname() << "\n";
	os << "Researcher id: " << r.getid() << "\n";
    os << "Researcher serialnum: " << r.getserialnum() << "\n";
	os << " num Of Articles: " <<r.getlogicalNumOfArticles() << "\n";
    
    for (int i = 0; i <r.getlogicalNumOfArticles(); i++)
	{
		os << " Researcher #" << (i + 1) << "\n";
        if (r.arrarticles[i]!=nullptr)
        {
            os << *r.arrarticles[i]<<"\n";

        } 
        else
        {
            os << "(null)\n";

        }
	}
	return os;

}


