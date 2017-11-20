#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct chance {
    string data;
    int pos = 0;
    int maxl = 0;
    void set(string x) {data = x; maxl=x.length();}
};

void getChances (vector<string> &charset, string &data);
void process(int &i, int &L, vector<string> &charset, vector<string> & words, string &newword, int &counter);

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
    int L, D, N;
    input >> L >> D >> N;
    getline(input, blank);

    vector<string> words;

    for(int i=0; i<D; i++) {
        string w;
        input >> w;
        words.push_back(w);
        getline(input, blank);
    }

    for(int cases=0; cases<N; cases++) {
        cout << "\n" << cases << endl;
        string data;
        input >> data;
        cout << "\n" << data << endl;
        getline(input, blank);

        vector<string> charset;
        getChances(charset, data);

        int counter = 0, i=1;
        string newword = "";
        process(i, L, charset, words, newword, counter);

        output << "Case #" << cases+1 <<": " << counter << endl;
    }

    input.close();
    output.close();
    return 0;
}

void getChances (vector<string> &charset, string &data) {
    unsigned int length = data.length(), processed = 0, startpos=0, endpos=0;
    string part;
    while(processed<length) {
        if(data[startpos] == '(') {
                endpos = data.find(')', startpos+1);
                unsigned int l = (endpos-startpos)-1;
                part = data.substr(startpos+1, l);
                charset.push_back(part);
                processed += (l+2);
                startpos = endpos+1;
           }
        else {
            part = data.substr(startpos, 1);
            charset.push_back(part);
            processed++;
            startpos++;
        }
    }
}

void process(int &i, int &L, vector<string> &charset, vector<string> & words, string &newword, int &counter) {
    string nword = newword;
    unsigned int size = charset[i-1].length();
    for(unsigned int m=0; m<size; m++) {
        nword += charset[i-1].substr(m,1);
        unsigned int D = words.size();
        vector<string> match;
        for(unsigned int n=0; n<D; n++) { //match the sub words with the alen words
            if(words[n].find(nword) != string::npos) {
                match.push_back(words[n]);
            }
        }

        if(match.size() > 0) {
            if(i==L) {
                cout << "Match: " << nword << endl;
                counter++;
            }
            else {
                int newi=i+1;
                process(newi, L, charset, match, nword, counter);
            }
        }
        else {
            nword = newword;
        }
    }
}
