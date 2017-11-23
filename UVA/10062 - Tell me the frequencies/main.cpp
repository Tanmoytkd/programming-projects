#include <bits/stdc++.h>

#define fs first
#define sc second

#define pf printf
#define pf1(x) printf("%d\n", x)
#define sf scanf
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)

#define pb push_back
#define Pb pop_back

#define pii pair<int, int>
#define mem(arr, x) memset((arr), (x), sizeof((arr)))
#define FOR(i,x) for(int (i)=0; (i)<(x); (i)++)

using namespace std;

bool comp(pii a, pii b) {
    if(a.sc==b.sc) return a.fs>b.fs;
    return a.sc<b.sc;
}

int main() {
    #ifdef TKD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    int t, tst=1;
    int ara[130];
    char str[15236];
    int flag=0;
    while(gets(str)) {
        vector<pii>vt;
        mem(ara, 0);
        int n=strlen(str);
        FOR(i, n) ara[str[i]]++;
        FOR(i, 130) if(ara[i]!=0) vt.pb(pii(i, ara[i]));
        sort(vt.begin(), vt.end(), comp);

        if(flag) pf("\n");
        flag=1;
        FOR(i, vt.size()) pf("%d %d\n", vt[i].fs, vt[i].sc);
    }

    return 0;
}
