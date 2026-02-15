#include <iostream>
#include "hospital.h"
#include "doctor.h"

using namespace std;

int main()
{
    Hospital hospital("Sheba");

    hospital.addDepartment("Cardiology");
    hospital.addDepartment("Neurology");
    hospital.addDepartment("Kids");
    
    Doctor d1("Levi", "Heart");
    Doctor d2("Cohen", "Brain");
    //Doctor d3("Levi", "Heart"); // d1=d3 , check if works
    Doctor d4("Sirin", "Eyes");

    hospital.addDoctor(d1, "Cardiology");
    hospital.addDoctor(d2, "Neurology");
    //hospital.addDoctor(d3, "Cardiology"); // same -> d1=d3
    hospital.addDoctor(d4, "Kids");

    hospital.addNurse("Dana", 5, "Cardiology");
    hospital.addNurse("Maya", 10, "Neurology");

    cout << endl << "--- Hospital Status ---" << endl;
    hospital.print();

    return 0;
}
