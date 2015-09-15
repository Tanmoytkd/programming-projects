#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string tunatxt;
    ofstream tuna("tuna.txt");

    cout << "Enter the data you want to put in the tuna.txt: " << endl;
    getline(cin, tunatxt);
    tuna << tunatxt << endl;
    tuna.close();
    return 0;
}
