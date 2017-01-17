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

int comp[100099];

void seive() {

    int mx=100099;
    int stop=sqrt(mx);
    for(int i=4; i<mx; i+=2) comp[i]=2;

    for(int i=3; i<=stop; i+=2) {
        if(comp[i]) continue;

        for(int j=i*i; j<mx; j+=2*i) {
            comp[j]=i;
        }
    }

    for(int i=1; i<mx; i++) {
        if(comp[i]) continue;
        comp[i]=i;
    }
}

int main()
{
    int n;
    sf1(n);

    seive();

    map<int, int> mp;

    int arr[n+1];
    FOR(i, n) {
        sf1(arr[i]);

        int num=arr[i];
        while(num!=1) {
            int divisor=comp[num];
            mp[divisor]++;

            while(divisor!=1 && num%divisor==0) {
                num/=divisor;
            }
        }
    }


    int res=1;
    map<int, int>::iterator it=mp.begin();

    for(it=mp.begin(); it!=mp.end(); it++) {

        res=max(res, it->second);
    }


    cout << res << endl;
    return 0;
}
