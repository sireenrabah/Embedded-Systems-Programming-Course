#ifndef ___RESEARCHER__CENTER_H__
#define ___RESEARCHER__CENTER_H__

#include <iostream>
#include <vector>
#include "researcher.h"

class ResearcherCenter
{
private:
    char* name;
    std::vector<Researcher*> researchers;

public:
    ResearcherCenter(const char* name);           
    ResearcherCenter(const ResearcherCenter& other)= delete;      
    ResearcherCenter& operator=(const ResearcherCenter& other)= delete;     
    ~ResearcherCenter();                         

    const char* getname() const { return name; }
    int getNumResearchers() const { return (int)researchers.size(); }
    const std::vector<Researcher*>& getResearchers() const { return researchers; }

    bool setname(const char* name);
    //bool setArticles(Articles* newArticle);
    bool researcherExist(const Researcher& r) const;///////////////////////
    bool assignResearcher(Researcher& r);

    friend std::ostream& operator<<(std::ostream& os, const ResearcherCenter& rc);
};



    






#endif
