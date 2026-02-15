#include <iostream>

#include "hospital.h"
#include "doctor.h"
#include "nurse.h"
#include "researcher.h"
#include "doctorresearcher.h"
#include "articles.h"

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

    // Add all employees to hospital (clone() keeps copies inside Hospital)
    h.addEmployee(d1);
    h.addEmployee(d2);
    h.addEmployee(n1);
    h.addEmployee(n2);
    h.addEmployee(r1);
    h.addEmployee(dr1);

    // Assign doctors to departments
    if (!h.addDoctortodepartment(d1, "Cardiology"))
        std::cout << "Failed to assign Alice to Cardiology\n";

    if (!h.addDoctortodepartment(d2, "Neurology"))
        std::cout << "Failed to assign Bob to Neurology\n";

    // Assign nurses to Cardiology (ONLY via setDepartment to avoid double-adding)
    Department* cardio = h.departmentExist("Cardiology");
    if (cardio)
    {
        n1.setDepartment(cardio);
        n2.setDepartment(cardio);
    }
    else
    {
        std::cout << "Cardiology department not found\n";
    }

    // Assign researchers to researcher center
    if (!h.addResearchertoResearchercenter(r1))
        std::cout << "Failed to assign researcher Charlie to ResearcherCenter\n";

    if (!h.addResearchertoResearchercenter(dr1))
        std::cout << "Failed to assign DoctorResearcher Maya to ResearcherCenter\n";

    // Articles
    Articles a1("Nature",  "AI in Medicine", 2024);
    Articles a2("Science", "Brain Signals", 2023);
    Articles a3("Lancet",  "Cancer Trials", 2022);

    // Attach articles to researchers
    r1.addArticle(a1);
    r1.addArticle(a2);
    dr1.addArticle(a3);

    // Print hospital / departments
    std::cout << "\n===== Hospital =====\n";
    std::cout << h << "\n";

    std::cout << "\n===== Departments =====\n";
    Department* dep1 = h.departmentExist("Cardiology");
    if (dep1) std::cout << *dep1 << "\n";

    Department* dep2 = h.departmentExist("Neurology");
    if (dep2) std::cout << *dep2 << "\n";

    // Print researchers (should include articles)
    std::cout << "\n===== Researchers =====\n";
    std::cout << r1 << "\n";
    std::cout << dr1 << "\n";

    std::cout << "\nDone.\n";
    return 0;
}
