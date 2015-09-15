#ifndef PEOPLE_H
#define PEOPLE_H
#include <iostream>
#include <string>
#include "Birthday.h"
using namespace std;

class people
{
    public:
        people(string name, Birthday bd);
        string getName();
        Birthday birthday();
    protected:
    private:
        string name;
        Birthday bd;
};

#endif // PEOPLE_H
