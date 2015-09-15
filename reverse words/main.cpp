#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string process(string x);
bool spaceCheck(string x);

int main()
{
    //string fileLocation;
    //cout << "Please enter the file name: ";
    //cin >> fileLocation;

    ifstream inFile("input.in");
    ofstream outFile("output.txt");

    int cases;
    string line1;
    inFile >> cases;
    getline(inFile, line1);

    string test[cases];

    for(int i=0; i<cases; i++) {
        getline(inFile, test[i]);
    }


    for(int m=0; m<cases; m++) {
        outFile << "Case #" << m+1 << ": " << process(test[m]) << endl;
    }

    inFile.close();
    outFile.close();
    return 0;
}

string process(string x) {
    string result="";
    //int words = 1;
    //int lastLocation=x.length();

    while(spaceCheck(x)) {
            int loc = x.rfind(" ");
            result+=x.substr(loc+1, x.length()-loc);
            result+= " ";
            //cout << result << endl;
            x.erase(loc);
            //lastLocation=loc-1;
            //words++;
    }
    result+=x;
    cout << result << endl;
    return result;
    //string wordList[words];
}

bool spaceCheck(string x) {
    int length=x.length();
    for(int i=0; i<length; i++) {
        if(isspace(x.at(i))) return true; //if there is space in the  string return true
    }
    return false; //if there is no space in the string return false
}
