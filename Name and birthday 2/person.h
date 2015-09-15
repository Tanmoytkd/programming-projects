#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Birthday.h"
using namespace std;

class person
{
    public:
        person(string name, Birthday bd);
        string getName();
        Birthday birthday();
    protected:
    private:
        const string name;
        const Birthday bd;
};

#endif // PERSON_H
