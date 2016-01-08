#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    string str[4];
    str[0] = "12345A5AcAd21";
    str[1] = "32A293AaAbAc3";
    str[2] = "AaAcAd8922113";
    str[3] = "Aa34442108131";

    for( int i=0; i<4; i++ ) { //for each string
        string line = str[i];

        regex e1(".*A.A.A.*"); //pattern = AxAxAx in any part of the string
        bool match = regex_match(line, e1);
        if(match) {
            cout << i << ": " << line << endl;
            //enter your code here
        }
    }

    return 0;
}
