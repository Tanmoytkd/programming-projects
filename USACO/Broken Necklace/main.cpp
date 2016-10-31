/*
ID: tanmoyk2
PROG: beads
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;

struct bead {
    char color;
    int counter;
    bead(char c, int x) {
        color = c;
        counter=x;
    }
};

int main() {

    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int n;
    sf1(n);

    string s;
    cin >> s;

    vector<bead> vec;

    vec.pb(bead(s[0], 1));
    for(int i=1; i<n; i++) {
        if(s[i]==s[i-1]) vec.back().counter++;
        else vec.pb(bead(s[i], 1));
    }

    int vecsize=vec.size();



    int imax=0;

    for(int i=0; i<vecsize; i++) {
        int counter=0;
        stack<char> col;
        for(int k=i; ; k++) {
            int j=k%vecsize;
            if(vec[j].color=='w') counter+=vec[j].counter;
            else if(col.empty()) {
                counter+=vec[j].counter;
                col.push(vec[j].color);
            }
            else if(vec[j].color==col.top()) {
                counter+=vec[j].counter;
            }
            else if(col.size()==1) {
                counter+=vec[j].counter;
                col.push(vec[j].color);
            }
            else break;

            if(counter>imax) imax=counter;

            if(j==i-1) break;
            if(i==0 && j==vecsize-1) break;
        }
    }

    pf1(imax);

    return 0;
}
