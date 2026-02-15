
#include <iostream>
#include <string.h>
using namespace std;

#include "articles.h"
   
   
   
   
Articles:: Articles (const char* MagazineName ,const char* articleName, int publicationDate) : MagazineName(nullptr),articleName(nullptr),publicationDate(publicationDate)///constrastor
{
    cout<<"In Person::Person \n";
    setMagazineName(MagazineName);
    setarticleName(articleName);


}

Articles:: Articles(const Articles& other) : MagazineName(nullptr),articleName(nullptr)
{
    cout<<"In Person::Person (copy)\n";
    *this=other;
}
const Articles& Articles::operator=(const Articles& other)
{
    if (this == &other)
        return *this;

    setMagazineName(other.MagazineName);
    setarticleName(other.articleName);
    publicationDate = other.publicationDate;

    return *this;
}

Articles::Articles(Articles&& other)
    : MagazineName(other.MagazineName),
      articleName(other.articleName),
      publicationDate(other.publicationDate)
{
    other.MagazineName = nullptr;
    other.articleName = nullptr;
}


Articles& Articles:: operator=( Articles&& other)
   {
    if(this!= &other){
        std:: swap(MagazineName,other.MagazineName);
        std:: swap(articleName,other.articleName);
        std:: swap(publicationDate,other.publicationDate);
        
    }
    return *this;

   }

bool Articles:: setMagazineName(const char* name)
{
    if (name == nullptr){
        return false;
        }  
        delete[] MagazineName;   
        MagazineName = new char[strlen(name) + 1];
        strcpy( MagazineName ,name); 
        return true; 

}
bool Articles:: setarticleName(const char* name)
{
    if (name == nullptr){
        return false;
        }  
        delete[] articleName;   
        articleName = new char[strlen(name) + 1];
        strcpy(articleName ,name); 
        return true; 

}

std::ostream& operator<< (std::ostream& os,const Articles& a)
{
    os << "The Articles Details: \n";
    os << "Magazine Name: " << a.getMagazineName() << "\n";
	os << "article Name: " << a.getarticleName() << "\n";
	os << "article publication Date: " << a.getpublicationDate() << "\n";
	return os;
}

Articles:: ~Articles()  //disconstractor
{
    cout<<"In Person::~Person \n";
    delete[] articleName;  
    delete[] MagazineName; 

}
