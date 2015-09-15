//#include "Birthday.h"
#include "people.h"

people::people(string name, Birthday bd)
:name(name), bd(bd)
{
    //ctor
}

string people::getName() {
    return name;
}

Birthday people::birthday() {
    return bd;
}
