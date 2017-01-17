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

int comp[1000100];

void seive() {
    int mx=1000100;
    comp[1]=1;
    for(int i=4; i<mx; i+=2) {
        comp[i]=1;
    }

    int stop=sqrt(mx);
    for(int i=3; i<=stop; i+=2) {
        if(comp[i]) continue;
        for(int j=i*i; j<mx; j+=2*i) {
            comp[j]=1;
        }
    }
}

int main()
{
    int t, tst = 1;
    seive();
    int n;
    sf1(n);

    FOR1(i, 1000) {
        if(comp[n*i+1]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
