
#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

#include "researcher.h"
   
Researcher::Researcher(const char* name, const int id)
    : Employee(name, id)
{
}

Researcher::Researcher(const Researcher& other)
    : Employee(other)
{
    articles.reserve(other.articles.size());
    for (auto a : other.articles)
        articles.push_back(a ? new Articles(*a) : nullptr);
}

Researcher& Researcher::operator=(const Researcher& other)
{
    if (this != &other)
    {
        Employee::operator=(other);

        for (auto a : articles) delete a;
        articles.clear();

        articles.reserve(other.articles.size());
        for (auto a : other.articles)
            articles.push_back(a ? new Articles(*a) : nullptr);
    }
    return *this;
}

Researcher::Researcher(Researcher&& other) noexcept
    : Employee(std::move(other)), articles(std::move(other.articles))
{
}

Researcher& Researcher::operator=(Researcher&& other) noexcept
{
    if (this != &other)
    {
        Employee::operator=(std::move(other));

        for (auto a : articles) delete a;
        articles = std::move(other.articles);
    }
    return *this;
}

Researcher::~Researcher()
{
    for (auto a : articles)
        delete a;
}

bool Researcher::hasArticle(const Articles& a) const
{
    for (auto p : articles)
    {
        if (!p) continue;

        if (std::strcmp(p->getarticleName(), a.getarticleName()) == 0 &&
            std::strcmp(p->getMagazineName(), a.getMagazineName()) == 0 &&
            p->getpublicationDate() == a.getpublicationDate())
            return true;
    }
    return false;
}

bool Researcher::addArticle(const Articles& a)
{
    for (auto art : articles)
    {
        if (std::strcmp(art->getarticleName(), a.getarticleName()) == 0 &&
            std::strcmp(art->getMagazineName(), a.getMagazineName()) == 0 &&
            art->getpublicationDate() == a.getpublicationDate())
        {
            return false;  // already exists
        }
    }

    articles.push_back(new Articles(a));
    return true;
}


std::ostream& operator<< (std::ostream& os,const Researcher& r)
{
    os << "The Researcher Details: \n";
    os << "Researcher Name: " << r.getname() << "\n";
	os << "Researcher id: " << r.getid() << "\n";
    os << "Researcher serialnum: " << r.getserialnum() << "\n";
	os << " num Of Articles: " << r.getNumOfArticles() << "\n";

    int i = 1;
    for (auto a : r.articles)
    {
        os << " Article #" << i++ << "\n";
        if (a) os << *a << "\n";
        else   os << "(null)\n";
    }
	return os;

}


