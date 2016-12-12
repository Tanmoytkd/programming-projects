/*
ID: tanmoyk2
PROG:
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
#define FOR(I, N) for(int I=0; I<N; I++)
#define FOR1(I, N) for(int I=1; I<=N; I++)

using namespace std;

#define mod 1000000007

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}

#define mx 1000001

string cube[mx];
vector<int> pir;

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif
    int total=5, base=2;
    while(total<mx) {
        pir.pb(total);
        char data[10];
        sprintf(data, "%d", base);
        cube[total]= string("") + data;
        cube[total]+= 'H';
        total+=(base+1)*(base+1);
        base++;
    }
    int t1=10, b1=3, t2=20, b2=4;
    while(t1<mx || t2<mx) {
        pir.pb(t1);
        pir.pb(t2);

        char data[10];
        sprintf(data, "%d", b1);
        cube[t1]= string("") + data;
        cube[t1]+= 'L';

        char d2[10];
        sprintf(d2, "%d", b2);
        cube[t2]= string("") + d2;
        cube[t2]+= 'H';

        t1+=(b1+2)*(b1+2);
        t2+=(b2+2)*(b2+2);
        b1+=2;
        b2+=2;
    }

    int c;
    while(sf1(c) && c) {
        vector<int>q, prev, prevpos;
        int pos=0;
    }


    return 0;
}
