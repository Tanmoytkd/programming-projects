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
using namespace std;
#define mx 31700

vector<long long> p;
vector<long long> sum;
char comp[mx];

void seive() {
    comp[1]=1;
    long long stop=sqrt(mx);
    p.pb(2);
    for(long long i=4; i<mx; i+=2) comp[i]=1;
    for(long long i=3; i<=stop; i+=2) {
        if(comp[i]) continue;
        p.pb(i);
        for(long long j=i*i; j<mx; j+=i+i) {
            comp[j]=1;
        }
    }
    for(long long i=stop+1; i<mx; i++) {
        if(!comp[i]) {
            p.pb(i);
        }
    }
}

long long iscomp(long long n) {
    long long stop=sqrt(n);
    for(long long i=0; i<p.size() && p[i]<=stop; i++) {
        if(n%p[i]==0) return 1;
    }
    return 0;
}

long long sumdig(long long n) {
    long long res=0;
    while(n>0) {
        res+= n%10;
        n/=10;
    }
    return res;
}

long long sumprime(long long n) {
    long long res=0;
    for(long long i=0; i<p.size() && p[i]<= n; i++) {
        while(n%p[i]==0) {
//            cout << p[i] << endl;
            n/=p[i];
            res+=sum[i];
        }
    }
    if(n>1) {
        res+=sumdig(n);
    }
    return res;
}

long long getres(long long n) {
    for(long long i=n+1; ; i++) {
//        cout << i << " " << sumdig(i) << " " << sumprime(i) << endl;
//        cout << iscomp(i) << endl;
        if(i<mx && (comp[i] && sumdig(i)==sumprime(i)) ) return i;
        else if(iscomp(i) && sumdig(i)==sumprime(i)) return i;

//        system("PAUSE");
    }
}


int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    seive();

    for(long long i=0; i<p.size(); i++) {
        sum.pb(sumdig(p[i]));
    }

    int t;
    sf1(t);

    while(t--) {
        long long int n;
        sf("%lld", &n);

        long long res=getres(n);
        pf("%lld\n", res);
    }
    return 0;
}
