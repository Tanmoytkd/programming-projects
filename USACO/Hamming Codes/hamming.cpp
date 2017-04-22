/*
ID: tanmoyk2
PROG: hamming
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");

    int n, b, d;

    fin >> n >> b >> d;

    vector <int> res;
    res.push_back(0);

    int up=(1<<b)-1;

    for(int i=1; i<=up; i++) {
        if(res.size()>=n) break;
        auto hamming = [] (int a, int b) {
            int dist=0;
            int m=max(a,b);

            for(int i=0; (1<<i)<=m; i++) {
                dist+= (((a>>i)&1) != ((b>>i)&1));
            }
            return dist;
        };
        auto check=[&res, hamming, d](int x) {
            int valid=1;
            for(int j=0; j<res.size(); j++) {
                if(hamming(x, res[j])<d) {
                    valid=0;
                    break;
                }
            }
            return valid;
        };

        if(check(i)) res.push_back(i);
    }

    for(int i=0; i<res.size(); i++) {
        if(i%10!=0) fout << " ";
        else if(i!=0) fout << endl;
        fout << res[i];
    }
    fout << endl;
    return 0;
}
