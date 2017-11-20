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

int main() {
    char str[1000];
    while(gets(str)!=NULL) {
        stringstream ss(str);
        string s;
        int first=1;
        while(ss>>s) {
            if(!first) pf(" ");
            first=0;
            reverse(s.begin(), s.end());
            pf("%s", s.c_str());
        }
        pf("\n");
    }
    return 0;
}
