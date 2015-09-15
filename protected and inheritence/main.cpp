#include <iostream>
#include "base.h"
#include "derived.h"
using namespace std;

int main()
{
    derived lzo;
    lzo.changeValues();

    lzo.pubv=99;
    cout << "pubv= " << lzo.pubv << endl;

    //lzo.prov=100;
    //cout << "prov= " << lzo.prov << endl;
    return 0;
}
