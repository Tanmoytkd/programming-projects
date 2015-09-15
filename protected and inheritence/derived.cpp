#include <iostream>
#include "base.h"
#include "derived.h"
using namespace std;


derived::derived()
{
    //ctor
}

void derived::changeValues() {
    pubv=12;
    cout << "pubv= " << pubv << endl;
    prov=23;
    cout << "prov= " << prov << endl;
    //priv=32;
    //cout << "priv= " << priv << endl;
}
