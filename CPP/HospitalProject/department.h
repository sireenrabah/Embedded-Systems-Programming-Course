#ifndef __DEPARTMENT_H__
#define __DEPARTMENT_H__

class Doctor; 
class Nurse;

class Department
{
private:
    char*       name;

    Doctor**    arrDoctor;
    int         physicalNumOfDoc;
    int         logicalNumOfDoc;
    Department* department;
    Nurse**     arrNurse;
    int         physicalNumOfNurse;
    int         logicalNumOfNurse;

public:
    Department(const char* name);
    Department(const Department&) = delete;
    Department& operator=(const Department&) = delete;
    ~Department();

    const char* getName() const                { return name; }
    bool        setName(const char* name);

    bool        assignDoctor(Doctor* doctor); 
    bool        doctorExists(const Doctor* doctor) const;

    bool        assignNurse(Nurse* nurse);
    bool        nurseExists(const Nurse* nurse) const;

    Department* getDepartment() const          { return department; }
    void        setDepartment(Department* dep) { department = dep; }

    void        print() const;
};

#endif
