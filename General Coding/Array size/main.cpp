#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 5> myarr {1,2,3,4,5};

    int l = myarr.size();
    for(int i=0; i<l; i++) { // using array size here
        cout << myarr[i] << endl;
    }

    cout << endl << endl;

    for(int elem : myarr) {
        ++elem;
        cout << elem << endl;
    }

    cout << endl << endl;

    for(int i=0; i<l; i++) {
        cout << myarr[i] << endl;
    }

    cout << endl << endl;

    return 0;
}
