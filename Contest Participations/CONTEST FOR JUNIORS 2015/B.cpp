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

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif
    int n;
    while(sf1(n)==1)
    {
        int a[n+1];
        int f=1,sum=0;
        for(int i=0; i<n; i++)
        {
            sf1(a[i]);
            sum+=a[i];
        }
        int real = n*(n-1)/2;
        int c=0;
        sort(a,a+n);
        for(int i=n-1; i>=0;i--)
        {
            int d = i-a[i];
            c+=d;
            if(c<0) f=0;
        }
        if(c!=0) f=0;
        if(sum==real && f) pf("1\n");
        else pf("-1\n");
    }


    return 0;
}

