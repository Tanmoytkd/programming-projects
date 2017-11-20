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

string * getChances (string &data, int L);
bool checkword(string word, string* words, int D);
bool checkword(string word, string* words, int D, int length);

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

    string *words = new string[D];

    for(int i=0; i<D; i++) {
        input >> words[i];
        getline(input, blank);
    }
    for(int cases=0; cases<N; cases++) {
        cout << "\n" << cases << " ";
        string data;
        input >> data;
        cout << "\n" << data << " ";
        getline(input, blank);
        string *chances = getChances(data, L);


        unsigned long long int countword=1;
        for(int m=0; m<L; m++) {
            countword *= chances[m].length();
        }

        chance * c = new chance[L];
        for(int i=0; i<L; i++) {
            c[i].set(chances[i]);
        }
        delete chances;

        int counter =0;

        for(unsigned int i=0; i<countword; i++) {
            string word = "";
            for(int ch=0; ch<L; ch++) {
                chance * group = &c[ch];
                word += group->data.substr(group->pos, 1);
                //if(checkword(word, words, D, ch+1) == false) { break; }
                int * pos = &(group->pos);

                if(ch == L-1) {
                        int cpre;
                    if(*pos == c[ch].maxl-1) {
                       *pos = 0;
                        c[ch-1].pos+=1;
                        for(cpre=ch-1; cpre>0; cpre--) {
                            if(c[cpre].pos >= c[cpre].maxl) {
                                c[cpre].pos = 0;
                                c[cpre-1].pos+=1;
                            }
                        }
                        if(cpre == 0 && c[cpre].pos >= c[cpre].maxl-1) c[cpre].pos = 0;
                    }
                    else group->pos += 1;
                }
            }
            //cout << "\n" << word << endl;
            if(checkword(word, words, D) == true) { counter ++; }
        }

        output << "Case #" << cases+1 <<": " << counter << endl;
        delete chances;
        delete c;

    }

    delete words;
    input.close();
    output.close();
    return 0;
}

string * getChances (string &data, int L) {
    string *chances = new string[L];
    int length = data.length(), startpos=0, endpos=0;
    int chancepos=0;
    int lastpos = 0;
        while(startpos<=length-1) {
            if(data.at(startpos) == '(') {
                endpos = data.find(')', lastpos);
                lastpos = endpos + 1;
                chances[chancepos] = data.substr(startpos+1, endpos-(startpos+1));
                //cout << chances[chancepos] << " ";
                startpos = endpos+1;
                chancepos++;
               }
            else {
                endpos=startpos;
                chances[chancepos] = data.substr(startpos, 1);
                //cout << chances[chancepos] << " ";
                chancepos++;
                startpos = endpos+1;
            }
        }
        return chances;
}


bool checkword(string word, string * words, int D) {

    for(int j=0; j<D; j++) {
        //cout << j << endl;
        //cout << word << endl;
        if(word == words[j]) return true;
    }
    return false;
}

bool checkword(string word, string * words, int D, int length) {
    for(int j=0; j<D; j++) {
        if(word == words[j].substr(0, length)) return true;
    }
    return false;
}
