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
    int up=0, left=0;
    string s;
    cin >> s;

    int len=s.length();
    for(int i=0; i<len; i++) {
        switch(s[i]) {
            case 'L': left++; break;
            case 'R': left--; break;
            case 'U': up++; break;
            case 'D': up--; break;
        }
    }
    up=abs(up);
    left=abs(left);

    int error=up+left;

    if(error&1) pf("-1\n");
    else pf("%d\n", error>>1);
    return 0;
}
