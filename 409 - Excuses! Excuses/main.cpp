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
            int pos=0, len=data.length();
            while(pos<len) {
                int start=1;
                string newword="";
                for(; pos<len; pos++) {
                    if(isalpha(data[pos])) {
                        if(start) start=0;
                        newword+=tolower(data[pos]);
                    }
                    else if(start) continue;
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
