#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

#include "articles.h"
   
Articles:: Articles (const char* MagazineName ,const char* articleName, int publicationDate) : MagazineName(nullptr),articleName(nullptr),publicationDate(publicationDate)///constrastor
{
    cout<<"In Articles::Articles \n";
    setMagazineName(MagazineName);
    setarticleName(articleName);
    cout<<"In Articles::~Articles \n";
}

Articles& Articles::operator=(const Articles& other)
{
    if (this != &other)
    {
        setMagazineName(other.MagazineName);
        setarticleName(other.articleName);
        publicationDate = other.publicationDate;
    }
    return *this;
}

Articles::Articles(Articles&& other) noexcept
    : MagazineName(other.MagazineName),
      articleName(other.articleName),
      publicationDate(other.publicationDate)
{
    other.MagazineName = nullptr;
    other.articleName = nullptr;
    other.publicationDate = 0;
}


Articles& Articles::operator=(Articles&& other) noexcept
{
    if (this != &other)
    {
        delete[] MagazineName;
        delete[] articleName;

        MagazineName = other.MagazineName;
        articleName  = other.articleName;
        publicationDate = other.publicationDate;

        other.MagazineName = nullptr;
        other.articleName = nullptr;
        other.publicationDate = 0;
    }
    return *this;
}

bool Articles::setMagazineName(const char* name)
{
    if (!name) return false;

    char* tmp = new char[std::strlen(name) + 1];
    std::strcpy(tmp, name);

    delete[] MagazineName;
    MagazineName = tmp;
    return true;
}

bool Articles::setarticleName(const char* name)
{
    if (!name) return false;

    char* tmp = new char[std::strlen(name) + 1];
    std::strcpy(tmp, name);

    delete[] articleName;
    articleName = tmp;
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

Articles::Articles(const Articles& other)
    : MagazineName(nullptr),
      articleName(nullptr),
      publicationDate(other.publicationDate)
{
    setMagazineName(other.MagazineName);
    setarticleName(other.articleName);
}
