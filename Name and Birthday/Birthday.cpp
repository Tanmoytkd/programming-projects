#include <iostream>
#include "Birthday.h"

using namespace std;

Birthday::Birthday(int d, int m, int y)
:itsDate(d), itsMonth(m), itsYear(y)
{
    //ctor
}

int Birthday::date() {
    return itsDate;
}

int Birthday::month() {
    return itsMonth;
}

int Birthday::year() {
    return itsYear;
}
