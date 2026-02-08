#include <iostream>
#include <cstring>

#include "Survivor.h"

using namespace std;

int Survivor::counter = 0;

Survivor::Survivor()
{
    name = nullptr;
    age = 0;
    status = Status::single;
    tribe = nullptr;
    id = ++counter;
}

void Survivor::setName(const char* newName)
{
    if (name != nullptr)
    {
        delete[]name;
    }
    int len = strlen(newName);
    name = new char[len+1];
    strcpy(name, newName);
}

void Survivor::setAge(int a)
{
    age = a;
}

void Survivor::setStatus(Status s)
{
    status = s;
}

Survivor::~Survivor()
{
    if (name != nullptr)
    {
        delete[]name;
    }
}

Survivor::Survivor(const Survivor& other)
{
    id = ++counter;
    tribe = nullptr;
    age = other.age;
    status = other.status;
    bandana = other.bandana;
    if (other.name == nullptr)
    {
        name = nullptr;
    }
    else
    {
        int len = strlen(other.name);
        name = new char[len+1];
        strcpy(name, other.name);

    }
}

void Survivor::print()const
{
    cout << "NAME: " << (name ? name : "No Name") << " , Id: " << id << " , AGE: " << age << " , STATUS: ";
    switch(status)
    {
        case Status::single:
        {
            cout << "Single";
            break;
        }
        case Status::married:
        {
            cout << "Married";
            break;
        }
        case Status::inRelationship:
        {
            cout << "In Relationship";
            break;
        }

    }
    cout << " , ";
    bandana.print();
    cout << endl;
}


void GetSurvivor(Survivor& s)
{
    char tempName[NAME_LEN];
    cout << "Enter Name: ";
    cin >> tempName;
    s.setName(tempName);

    int a;
    cout << "Enter Age: ";
    cin >> a;
    s.setAge(a);

    char ch;
    cout << "Status (1=Single, 2=Married, 3=In Relationship): ";
    cin >> ch;
    if (ch=='1') 
    {
        s.setStatus(Status::single);
    }
    else if (ch =='2')
    {
        s.setStatus(Status::married);
    }
    else
    {
        s.setStatus(Status::inRelationship);
    }

    char c[20];
    int len;

    cout << "Bandana color: ";
    cin >> c;

    cout << "Bandana length: ";
    cin >> len;

    s.setBandana(c, len);
}


Tribe::Tribe(int max, const char* name) 
{
    strcpy(tribeName, name);
    maxSurvivors = max;
    survivors = new Survivor*[maxSurvivors];
    count = 0;
}

Tribe::~Tribe()
{
    for (int i = 0 ; i < count ; i++)
    {
        delete survivors[i];
    }
    delete[]survivors;
}

Tribe::Tribe(const Tribe& other)
{
    strcpy(tribeName, other.tribeName);
    maxSurvivors = other.maxSurvivors;
    count = other.count;
    survivors = new Survivor*[maxSurvivors];
    for (int i = 0 ; i < count ; i++)
    {
        survivors[i] = new Survivor(*other.survivors[i]);
    }
}

void Tribe::addSurvivor()
{
    if (isFull())
    {
        cout << "No space in tribe: " << tribeName << endl;
        return;
    }

    survivors[count] = new Survivor;
    GetSurvivor(*survivors[count]);
    survivors[count]->setTribe(this);
    count++;
}


void Tribe::print() const
{
    cout << "Tribe name: " << tribeName << endl;
    for (int i = 0 ; i < count ; i++)
        survivors[i]->print();
}


void Survivor::setTribe(Tribe* t)
{
    tribe = t;
}

Bandana::Bandana()
{
    color = nullptr;
    length = 0;
}

Bandana::Bandana(const char* c, int len)
{
    length = len;
    int n = strlen(c);
    color = new char[n+1];
    strcpy(color, c);
}

void Bandana::print() const
{
    cout << "Bandana: " << (color ? color : "No Color") << " , Length: " << length;
}

void Survivor::setBandana(const char* c, int len)
{
    bandana = Bandana(c, len);
}

Bandana::Bandana(const Bandana& other)
{
    length = other.length;
    if (other.color == nullptr)
    {
        color = nullptr;
    }
    else
    {
        int n = strlen(other.color);
        color = new char[n+1];
        strcpy(color, other.color);
    }
}

Bandana::Bandana(Bandana&& other)
{
    length = other.length;
    color = other.color;
    other.color = nullptr;
    other.length = 0;
}

Bandana& Bandana::operator=(const Bandana& other)
{
    if (this != &other)
    {
        return *this;
    }

    delete []color;

    length = other.length;

    if (other.color == nullptr)
    {
        color = nullptr;
    }
    else
    {
        int n = strlen(other.color);
        color = new char[n+1];
        strcpy(color, other.color);
    }
    return *this;
}

Bandana& Bandana::operator=(Bandana&& other)
{
    if (this == &other)
    {
        return *this;
    }
    delete []color;

    color = other.color;
    length = other.length;

    other.color = nullptr;
    other.length = 0;

    return *this;
}

Bandana::~Bandana()
{
    delete []color;
}