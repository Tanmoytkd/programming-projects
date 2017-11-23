#include <bits/stdc++.h>
using namespace std;

struct pii{
    long long length, ways;
    pii() {
        length=LLONG_MAX;
        ways=0;
    }
    pii(long long int a, long long int b) {
        length=a,ways=b;
    }

    pii operator+ ( pii b) {
        if(length<b.length) return pii(length, ways);
        else if(length>b.length) return b;
        else return pii(length, ways+b.ways);
    }

    bool operator==(pii b) {
        return length==b.length && ways==b.ways;
    }
} dp[40][40];;
char s1[40], s2[40];
long long int l1, l2;
pii inf(LLONG_MAX, 0);

pii go(int p1, int p2) {
    if(p1==l1) return pii(l2-p2, 1);
    if(p2==l2) return pii(l1-p1, 1);
    if(dp[p1][p2]==inf) {
        pii & ret = dp[p1][p2];
        if(s1[p1]==s2[p2]) {
            ret=go(p1+1, p2+1);
            ret.length=ret.length+1;
        }
        else {
            ret=go(p1+1, p2);
            ret=ret + go(p1, p2+1);
            ret.length=ret.length+1;
        }
    }
    return dp[p1][p2];
}

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    scanf("%d", &t);

    for(int tst=1; tst<=t; tst++) {
        for(int i=0; i<40; i++) {
            for(int j=0; j<40; j++) {
                dp[i][j]= pii(LLONG_MAX, 0);
            }
        }
        scanf("%s", s1);
        scanf("%s", s2);

        l1=strlen(s1), l2=strlen(s2);

        pii res = go(0, 0);

        printf("Case %d: %lld %lld\n", tst, res.length, res.ways);
    }
    return 0;
}
