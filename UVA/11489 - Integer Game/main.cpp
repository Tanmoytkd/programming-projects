#include <bits/stdc++.h>

#define pf printf
#define pf1(x) printf("%d\n", x)
#define sf scanf
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)

#define pb push_back
#define Pb pop_back

using namespace std;

int main() {
    #ifdef TKD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    int test;
    char num[1024];
    sf1(test);

    for(int t=1; t<=test; t++) {
        int sum=0, mod[3];
        mod[0]=mod[1]=mod[2]=0;

        sf("%s", num);
        int len=strlen(num);
        for(int i=0; i<len; i++) {
            int dig=num[i]-'0';
            sum+=dig;
            mod[dig%3]++;
        }

        int counter=mod[0]+((sum%3)>0);

        pf("Case %d: ", t);
        if((sum%3)>0 && mod[sum%3]==0) pf("T\n");
        else if(counter&1) pf("S\n");
        else pf("T\n");
    }


    return 0;
}
