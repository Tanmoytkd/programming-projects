#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%lld\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%lld",&a)
#define sf2(a,b) scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pcase(x) printf("Case %lld: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
lint fin[200], dp[107][1007], c,s,e,t, pro[107][107];

lint go(lint node, lint tr) {
    if(tr==0) {
        if(fin[node]) return 0;
        else return INT_MIN;
    }
    if(dp[node][tr]==-1) {
        lint res=INT_MIN;
        FOR1(i, c) {
            if(i==node) continue;
            res=max(res, pro[node][i]+go(i, tr-1));
        }
        dp[node][tr]=res;
    }
    return dp[node][tr];
}

int main()
{
    while(sf3(c,s,e)==3 && sf1(t)==1 && (c||s||s||t)) {
        FOR1(i,c) {
            FOR1(j, c) {
                sf1(pro[i][j]);
            }
        }

        mem(fin, 0);
        FOR1(i, e) {
            int x;
            sf1(x);
            fin[x]=1;
        }
        mem(dp, -1);
        lint res= go(s, t);
        pf1(res);
    }
    return 0;
}
