#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string process(string x);

class keypad {
    public:
    int key(char x) {
        if(x=='a' || x=='b' || x=='c') return 2;
        else if(x=='d' || x=='e' || x=='f') return 3;
        else if(x=='g' || x=='h' || x=='i') return 4;
        else if(x=='j' || x=='k' || x=='l') return 5;
        else if(x=='m' || x=='n' || x=='o') return 6;
        else if(x=='p' || x=='q' || x=='r' || x=='s') return 7;
        else if(x=='t' || x=='u' || x=='v') return 8;
        else if(x=='w' || x=='x' || x=='y' || x=='z') return 9;
        else return 0;

    }
    string processChar(char x) {
        if(x=='a') return "2";
        else if(x=='b') return "22";
        else if(x=='c') return "222";
        else if(x=='d') return "3";
        else if(x=='e') return "33";
        else if(x=='f') return "333";
        else if(x=='g') return "4";
        else if(x=='h') return "44";
        else if(x=='i') return "444";
        else if(x=='j') return "5";
        else if(x=='k') return "55";
        else if(x=='l') return "555";
        else if(x=='m') return "6";
        else if(x=='n') return "66";
        else if(x=='o') return "666";
        else if(x=='p') return "7";
        else if(x=='q') return "77";
        else if(x=='r') return "777";
        else if(x=='s') return "7777";
        else if(x=='t') return "8";
        else if(x=='u') return "88";
        else if(x=='v') return "888";
        else if(x=='w') return "9";
        else if(x=='x') return "99";
        else if(x=='y') return "999";
        else if(x=='z') return "9999";
        else if(x==char(32)) return "0";
        else return "0";
    }
    string processChar(char x, char y) {
        if(key(x)==key(y)) return processChar(x)+" ";
        else return processChar(x);
    }
};

int main()
{
    string inputLoc, outputLoc;
    cout << "Please enter the location or name of the input file: ";
    getline(cin, inputLoc); //get the input file
    cout << "Please enter the location or name of the output file: ";
    getline(cin, outputLoc); //create the output file

    ifstream input(inputLoc.c_str());
    ofstream output(outputLoc.c_str());

    int cases;
    input >> cases;
    string blank;
    getline(input, blank);

    //getting all the test data
    string testCase[cases];
    for (int test0=0; test0<cases; test0++) {
        getline(input, testCase[test0]);
    }

    for(int test=0; test<cases; test++) {
        //cout << testCase[test] << endl;
        output << "Case #" << test+1 << ": " << process(testCase[test]) << endl;
    }

    input.close();
    output.close();
    return 0;
}

string process(string x) {
    string result="";
    keypad k1;
    int length=x.length();
    for(int pos=0; (pos+1)<length; pos++) {
        result += k1.processChar(x.at(pos), x.at(pos+1));
        //cout << x.at(pos) << " " << x.at(pos+1) << endl;
    }
    result += k1.processChar(x.at(length-1));
    //cout << result << endl;
    return result;
}
