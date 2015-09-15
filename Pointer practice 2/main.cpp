#include <iostream>

using namespace std;

int main()
{
    int tuna = 65;
    int luna = 77;

    int *tunaPointer = &tuna;
    cout << tunaPointer << endl;

    *tunaPointer = 23;
    cout << tuna;
    return 0;
}
