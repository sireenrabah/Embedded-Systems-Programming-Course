#include <iostream>
#include "Survivor.h"

using namespace std;

int main()
{
    int size;
    cout << "Number of survivors in each tribe: ";
    cin >> size;

    char name1[20];
    char name2[20];
    cout << "Enter tribe 1 name: ";
    cin >> name1;
    cout << "Enter tribe 2 name: ";
    cin >> name2;

    Tribe tribe1(size, name1);
    Tribe tribe2(size, name2);

    while (true)
    {
        if (tribe1.isFull() && tribe2.isFull())
        {
            cout << "Both tribes are full! No space left." << endl;
            break;
        }

        char cont;
        cout << "Add survivor? (y/n): ";
        cin >> cont;

        if (cont != 'y')
            break;

        char choice;
        cout << "Choose tribe (1 or 2): ";
        cin >> choice;

        if (choice == '1')
            tribe1.addSurvivor();
        else if (choice == '2')
            tribe2.addSurvivor();
        else
            cout << "Invalid tribe choice!" << endl;
    }

    cout << "----------------------------" << endl;
    tribe1.print();

    cout << "----------------------------" << endl;
    tribe2.print();

    return 0;
}
