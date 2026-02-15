#ifndef __VISIT_H__
#define __VISIT_H__

#include <iostream>

class Visit
{
private:
    char* visitDay;
    char* purposeofvisit;

public:
    Visit(const char* visitDay, const char* purposeofvisit);

    Visit(const Visit& other);
    const Visit& operator=(const Visit& other);

    Visit(Visit&& other);
    Visit& operator=(Visit&& other);

    ~Visit();

    const char* getvisitDay() const { return visitDay; }
    const char* getpurposeofvisit() const { return purposeofvisit; }

    bool setvisitDay(const char* visitDay);
    bool setpurposeofvisit(const char* purposeofvisit);

    friend std::ostream& operator<<(std::ostream& os, const Visit& v);
};

#endif
