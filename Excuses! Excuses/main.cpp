#include <bits/stdc++.h>

using namespace std;
struct excuse {
    int lame;
    string exc;

    excuse() {
        lame = 0;
        exc="";
    }

    excuse(string s) {
        lame=0;
        exc=s;
    }

    void operator++ (int) {
        lame++;
    }
};


int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k, e, test=0;
    string blank, data;
    while (cin >> k >> e) {
        test++;
        getline(cin, blank);
        map<string,int> key;
        excuse exc[e];
        for(int i=0; i<k; i++) {
            getline(cin, data);
            key[data]=1;
        }

        for(int i=0; i<e; i++) {
            getline(cin, data);
            exc[i]=data;
            stringstream ss(data);
            string word;
            while(ss>>word) {
                string newword="";
                for(int j=0; j<word.length(); j++){
                    if(isalpha(word[j])) newword+=tolower(word[j]);
                    else break;
                }
                if(key.find(newword)!=key.end()) {
                    exc[i]++;
                }
            }
        }

        int imax=0;
        for(int i=0; i<e; i++) {
            if(exc[i].lame>imax) imax=exc[i].lame;
        }

        cout << "Excuse Set #" << test << endl;
        for(int i=0; i<e; i++) {
            if(exc[i].lame==imax) cout << exc[i].exc << endl;
        }

        cout << endl;

    }
    return 0;
}
