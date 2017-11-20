#include <bits/stdc++.h>

#define pf printf
#define pf1(x) printf("%d\n", x)
#define sf scanf
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)

#define pb push_back
#define Pb pop_back

using namespace std;

int age[101];

int main() {
    #ifdef TKD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    int n;
    while(sf1(n)==1) {
        if(n==0) break;

        int a;
        for(int i=0; i<n; i++) {
            sf1(a);
            age[a]++;
        }

        int first=1;
        for(int i=1; i<101; i++) {
            while(age[i]>0) {
                if(!first) pf(" ");
                else first=0;

                pf("%d", i);
                age[i]--;
            }
        }
        pf("\n");
    }

    return 0;
}
