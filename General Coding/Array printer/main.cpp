#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printOut(int tkd[], int sizeOfTkd);
void printOut(int tkd, int n);

int main()
{
    int n, l, low, up;
    cout << "Please enter the length of the array: ";
    cin >> l;
    cout << "Please enter the lower limit of the array: ";
    cin >> low;
    cout << "Please enter the upper limit of the array: ";
    cin >> up;
    cout << "-------------------------------\n" << endl;
    int tkd[l];
    srand(time(0));
    for(int i=0; i<l; i++) {
        tkd[i] = rand()%(up+1-low)+low;
    }
    int sizeOfTkd = sizeof(tkd)/sizeof(tkd[0]);
    //cout << sizeOfTkd << endl;

    printOut(tkd, sizeOfTkd);

    cout << "\nPlease enter a number: ";
    cin >> n;
    printOut(tkd[n-1], n);
    return 0;
}

void printOut(int tkd[], int sizeOfTkd) {
        for(int i=0; i<sizeOfTkd; i++ ) {
        cout << "tkd[" << i << "] : " << tkd[i] << endl;
    }
}


void printOut(int tkd, int n) {
    cout << "\n------------------\n" << "The " << n << "th member of the array " << "(tkd[" << n-1 << "]) is " << tkd << "\n------------------\n" << endl;
}
