#ifndef __DOCTOR_RESEARCHER_H__
#define __DOCTOR_RESEARCHER_H__

//#include "department.h"

 #include "researcher.h"
 #include "doctor.h"

class DoctorResearcher : public Researcher, public Doctor
{

private:


public:

    DoctorResearcher (const char* name,const char* specialization, const int id);///constrastor
   // DoctorResearcher(const DoctorResearcher& other)=delete;
   // DoctorResearcher& operator=(const DoctorResearcher& other);
    //~DoctorResearcher();//disconstrastor
    virtual Employee* clone() const override { return new DoctorResearcher(*this);}
    
    friend std::ostream& operator<<(std::ostream& os, const DoctorResearcher& dr);
    
};






#endif
