#include "person.h"

person::person(string name, Birthday bd)
:name(name), bd(bd)
{
    //ctor
}

string person::getName() {
    return name;
}

Birthday person::birthday() {
    return bd;
}
