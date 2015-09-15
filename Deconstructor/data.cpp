#include <iostream>
#include "data.h"

using namespace std;

data::data()
{
    cout << "Construct!!!" << endl;
}

data::~data()
{
    int s;
    cout << "Enter a number: " ;
    cin >> s;
    cout << "\n\nThe number you entered is " << s << endl;
}
