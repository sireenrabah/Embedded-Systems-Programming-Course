#ifndef __PERSON_H__
#define __PERSON_H__

class Person
{
protected:
    char* name;

public:
    Person(const char* name);
    Person(const Person& other);
    Person&    operator=(const Person& other);
    virtual    ~Person();

    const char* getName() const       { return name; }
    bool        setName(const char* name);

    virtual void print() const;
};

#endif
