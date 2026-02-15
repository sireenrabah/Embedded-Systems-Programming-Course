#ifndef ___RESEARCHER__CENTER_H__
#define ___RESEARCHER__CENTER_H__

#include <iostream>

#include "researcher.h"

class ResearcherCenter
{
private:
    char* name;
    Researcher** researcherarr;
    int logicalNumOfResearchers;
    int physicalNumOfResearchers;
   
    
public:
    ResearcherCenter(const char* name);           
    ResearcherCenter(const ResearcherCenter& other)= delete;      
    ResearcherCenter& operator=(const ResearcherCenter& other)= delete;     
    ~ResearcherCenter();                         



    const char* getname() const { return name; }
    int getlogicalNumOfResearchers() const { return logicalNumOfResearchers; }
    //void clearDepartmentPtr();
    



    bool setname(const char* name);
    //bool setArticles(Articles* newArticle);
    bool researcherExist(const Researcher& r) const;///////////////////////
    bool assignResearcher(Researcher& r);



    friend std::ostream& operator<<(std::ostream& os, const ResearcherCenter& rc);
};



    






#endif
