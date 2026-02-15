#ifndef __RESEARCHER_H__
#define __RESEARCHER_H__

#include <iostream>
#include "employee.h"
#include "articles.h"

//#include "department.h"
class Department;


class Researcher : virtual public Employee
{

private:

    Articles** arrarticles;
    int logicalNumOfArticles;//logicalNum
    int physicalNumOfArticles;//physicalnum

    //Department* myDepartment;

    
public:

    Researcher(const char* name, int id); ///constrastor
    Researcher(const Researcher& other);
    const Researcher& operator=(const Researcher& other);
    Researcher( Researcher&& other);
    Researcher& operator=( Researcher&& other);
    
    virtual ~Researcher();//disconstrastor


    int getlogicalNumOfArticles()   const {return logicalNumOfArticles;}
    //int getmaxArticles()   const {return maxArticles;}
    //const Department* getDepartment() const {return myDepartment;}
    const Articles* const* getArticles() const { return arrarticles; }
    //void clearDepartmentPtr();
    virtual Employee* clone() const override {return new Researcher(*this);}



    //bool setDepartment(Department* newDepartment);
    //bool setArticles(Articles* newArticle);

   // bool setmaxArticles(int maxArticlesg);


    friend std::ostream& operator<<(std::ostream& os, const Researcher& r);




    
};






#endif
