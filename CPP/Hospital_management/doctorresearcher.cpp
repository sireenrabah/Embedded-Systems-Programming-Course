#include "doctorresearcher.h"

DoctorResearcher::DoctorResearcher(const char* name, const char* specialization, int id)
    : Employee(name, id),  
      Doctor(name, specialization, id),
      Researcher(name, id)
{
}

std::ostream& operator<<(std::ostream& os, const DoctorResearcher& dr)
{
    os << "DoctorResearcher:\n";

    os << static_cast<const Doctor&>(dr) << "\n";
    os << static_cast<const Researcher&>(dr) << "\n";

    return os;
}
