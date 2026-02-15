#ifndef __RESEARCHER_H__
#define __RESEARCHER_H__

#include <iostream>
#include <vector>

#include "employee.h"
#include "articles.h"
//#include "department.h"

class Department;

class Researcher : virtual public Employee
{
private:
    std::vector<Articles*> articles;
    
public:

    Researcher(const char* name, int id); ///constructor
    Researcher(const Researcher& other);
    Researcher& operator=(const Researcher& other);
    Researcher(Researcher&& other) noexcept;
    Researcher& operator=(Researcher&& other) noexcept;

    bool addArticle(const Articles& a);
    bool hasArticle(const Articles& a) const;

    virtual ~Researcher();   //destructor

    int getNumOfArticles() const { return (int)articles.size(); }
    const std::vector<Articles*>& getArticles() const { return articles; }

    virtual Employee* clone() const override {return new Researcher(*this);}

    friend std::ostream& operator<<(std::ostream& os, const Researcher& r);
    
};






#endif
