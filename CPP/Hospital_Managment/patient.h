#ifndef __PATIENT_H__
#define __PATIENT_H__
#include <iostream>
#include "person.h"

class Patient : public Person
{
private:
    char* gender; 
    int birthyear;
    
    
public:

    Patient(const char* name, int id, const char* gender, int birthyear); ///constrastor

    Patient(const Patient& other); //copy constructor
    Patient( Patient&& other) noexcept;
    Patient& operator=(const Patient& other);
    Patient& operator=( Patient&& other) noexcept;
    ~Patient(); //destructor

    int getbirthyear()      const {return birthyear;}
    const char* getgender()   const {return gender;}

    bool setbirthyear(const int birthyear);
    bool setgender(const char* gender);



    friend std::ostream& operator<< (std::ostream& os,const Patient& p);

    
};






#endif
