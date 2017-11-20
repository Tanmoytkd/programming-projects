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
    int t;
    sf1(t);
    char str[10001];
    gets(str);
    while(t--) {
        gets(str);
        int len=strlen(str);
        int sq=sqrt(len);
        if(sq*sq!=len) {
            puts("INVALID");
            continue;
        }
        for(int i=0; i<sq; i++) {
            for(int j=0; j<len; j+=sq) {
                pf("%c", str[j+i]);
            }
        }
        pf("\n");
    }
    return 0;
}
