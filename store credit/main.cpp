#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string inputLoc, outputLoc;
    cout << "Please enter the location or name of the input file: ";
    getline(cin, inputLoc);
    cout << "Please enter the location or name of the output file: ";
    getline(cin, outputLoc);

    ifstream input(inputLoc.c_str());
    ofstream output(outputLoc.c_str());

    int cases;
    input >> cases;

    for(int testCase=0; testCase<cases; testCase++) {
        int credit, item;
        string blank;
        input >> credit;
        cout << credit << endl;
        getline(input, blank);
        input >> item;
        int* items = new int[item];

        //assign values to items array
        for(int i=0; i<item; i++) {
            input >> items[i];
        }

        for(int m=0; m<item; m++) {
            for (int n=m+1; n<item; n++) {
                if(items[m]+items[n]==credit) {
                    output << "Case #" << testCase+1 << ": " << m+1 << " " << n+1 << endl;
                    cout << "Case #" << testCase+1 << ": " << m+1 << " " << n+1 << endl;
                }
            }
        }
    }

    input.close();
    output.close();
    return 0;
}
