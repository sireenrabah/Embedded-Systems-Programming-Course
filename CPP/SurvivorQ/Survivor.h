constexpr int NAME_LEN = 20;

#ifndef SURVIVOR_H
#define SURVIVOR_H

enum class Status
{
    single,
    married,
    inRelationship
};

class Bandana
{
private:
    char* color;
    int length;
public:
    Bandana();
    Bandana(const char* c, int len);
    Bandana(const Bandana& other);
    Bandana(Bandana&& other);      // stealing address
    Bandana& operator=(const Bandana& other);
    Bandana& operator=(Bandana&& other);
    void print() const;
};

class Tribe;

class Survivor
{
private:
    char* name;
    int age;
    Status status;
    Bandana bandana;
    static int counter;
    int id;
    Tribe* tribe;
public:
    Survivor();
    Survivor(const Survivor& other);
    ~Survivor();
    void setName(const char* newName);
    void setAge(int a);
    void setStatus(Status s);
    void setBandana(const char*c, int len);
    void setTribe(Tribe* t);
    void print() const;
};


void GetSurvivor(Survivor& s);

void printSurvivor(const Survivor& s);

class Tribe
{
private:
    char tribeName[NAME_LEN];
    int maxSurvivors;
    Survivor** survivors;
    int count;
public:
    Tribe(int max, const char* name);
    Tribe(const Tribe& other);
    ~Tribe();
    inline bool isFull() const { return count == maxSurvivors; }
    void addSurvivor();
    void print() const;
};

#endif
