#ifndef __DOCTOR_RESEARCHER_H__
#define __DOCTOR_RESEARCHER_H__

#include <iostream>
#include "doctor.h"
#include "researcher.h"

class DoctorResearcher : public Doctor, public Researcher
{
public:
    DoctorResearcher(const char* name, const char* specialization, int id);

    virtual Employee* clone() const override { return new DoctorResearcher(*this); }

    friend std::ostream& operator<<(std::ostream& os, const DoctorResearcher& dr);
};

#endif
