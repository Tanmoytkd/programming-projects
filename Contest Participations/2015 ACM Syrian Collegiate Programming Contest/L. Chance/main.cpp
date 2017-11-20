#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

#define mx 100007

int comp[mx], bits[mx], totalprime[mx];

void seive() {
    comp[0]=comp[1]=1;
    for(int i=4; i<mx; i+=2) comp[i]=1; //all even numbers are composite
    int stop=sqrt(mx);
    for(int i=3; i<=stop; i+=2) {
        if(comp[i]) continue;
        for(int j=i*i; j<mx; j+=i*2) comp[j]=1;
    }
}

int main()
{
    seive();
    int t;
    FOR1(i, mx-1) bits[i]=__builtin_popcount(i);
    FOR1(i, mx-1) totalprime[i]=totalprime[i-1]+(!comp[bits[i]]);
    sf1(t);

    while(t--) {
        int l, r;
        sf2(l, r);

        if(l==0) printf("%d\n", totalprime[r]);
        else printf("%d\n", totalprime[r]-totalprime[l-1]);
    }

    return 0;
}
