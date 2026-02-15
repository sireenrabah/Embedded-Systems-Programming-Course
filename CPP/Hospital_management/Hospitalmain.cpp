#include <iostream>

#include "hospital.h"
#include "doctor.h"
#include "nurse.h"
#include "researcher.h"
#include "doctorresearcher.h"

using namespace std;

int main()
{
    Hospital h("Rambam");

    // Departments
    h.addDepartment("Cardiology");
    h.addDepartment("Neurology");

    // Employees
    Doctor d1("Alice", "Heart", 111);
    Doctor d2("Bob", "Brain", 222);

    Nurse n1("Dana", 5, 333);      // (name, yearsExperience, id)
    Nurse n2("Eden", 2, 444);

    Researcher r1("Charlie", 555); // (name, id)

    DoctorResearcher dr1("Maya", "Oncology", 666);

    // Add all employees to hospital (IMPORTANT: before assigning to departments/center)
    h.addEmployee(d1);
    h.addEmployee(d2);
    h.addEmployee(n1);
    h.addEmployee(n2);
    h.addEmployee(r1);
    h.addEmployee(dr1);

    // Assign doctors to departments
    if (!h.addDoctortodepartment(d1, "Cardiology"))
        cout << "Failed to assign Alice to Cardiology\n";

    if (!h.addDoctortodepartment(d2, "Neurology"))
        cout << "Failed to assign Bob to Neurology\n";

    // If you have a similar function for nurses in Hospital (e.g., addNursetodepartment),
    // use it here. If not, you can assign via Department directly:
    Department* cardio = h.departmentExist("Cardiology");
    if (cardio)
    {
        cardio->assignNurse(n1);
        n1.setDepartment(cardio);

        cardio->assignNurse(n2);
        n2.setDepartment(cardio);
    }

    // Assign researcher to researcher center
    if (!h.addResearchertoResearchercenter(r1))
        cout << "Failed to assign researcher Charlie to ResearcherCenter\n";

    // Print departments (with people inside)
    cout << "\n===== Departments =====\n";
    Department* dep1 = h.departmentExist("Cardiology");
    if (dep1) cout << *dep1 << "\n";

    Department* dep2 = h.departmentExist("Neurology");
    if (dep2) cout << *dep2 << "\n";

    // Print hospital employees (if you created operator<< for Hospital, you can do cout << h)
    cout << "\n===== All Employees =====\n";
    cout << d1 << "\n";
    cout << d2 << "\n";
    cout << n1 << "\n";
    cout << n2 << "\n";
    cout << r1 << "\n";
    cout << dr1 << "\n";

    cout << "\nDone.\n";
    return 0;
}
