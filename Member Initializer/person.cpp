#include <iostream>
#include "person.h"
using namespace std;

person::person(int age)
: itsAge(age)
{

}

void person::printAge() {
    cout << "Age is " << itsAge << endl;
}

person::~person()
{
    cout << "The age was " << itsAge << endl;
}
