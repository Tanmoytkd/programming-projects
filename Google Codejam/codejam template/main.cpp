#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string inputLoc, outputLoc;
    cout << "Please enter the location or name of the input file: ";
    getline(cin, inputLoc); //get the input file
    cout << "Please enter the location or name of the output file: ";
    getline(cin, outputLoc); //get the output file

    ifstream input(inputLoc.c_str());
    ofstream output(outputLoc.c_str());

    //type your code here

    return 0;
}
