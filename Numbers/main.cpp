#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string inputLoc, outputLoc;
    cout << "Please enter the location or name of the input file: ";
    getline(cin, inputLoc); //get the input file
    cout << "Please enter the location or name of the output file: ";
    getline(cin, outputLoc); //create the output file

    ifstream input(inputLoc.c_str());
    ofstream output(outputLoc.c_str());

    string blank;
    int cases;
    input >> cases;
    getline(input, blank);

    for(int t=0; t<cases; t++) {
        int n;
        input >> n;
        getline(input, blank);

        long double base = 3 + sqrt(5);
        //cout << base << endl;
        long double powered = 1;
        for(int i=0; i<n; i++) {
            powered *= base;
        }
        cout << "double powered = " << powered << endl;
        unsigned long long int intPowered = (unsigned long long int) powered;
        long long int res = intPowered%1000;
        cout << "The result is " << res << endl;

        if(res <=99 && res > 9){
            output << "Case #" << t+1 << ": " << "0" << res << endl;
        }
        else if(res <= 9){
            output << "Case #" << t+1 << ": " << "00" << res << endl;
        }
        else {
            output << "Case #" << t+1 << ": " << res << endl;
        }
    }

    input.close();
    output.close();
    return 0;
}
