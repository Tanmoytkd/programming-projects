#include<bits/stdc++.h>
#define pii pair<lint,lint>
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
#define FOR(i,x) for(lint i=0;i<(x); i++)
#define FOR1(i, x) for(lint i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

lint dp[1<<18], n, dist[20][20], m ;

lint rec(lint mask) {
    if(mask==0) return 0;
    if(dp[mask]==-1) {
        lint res=INT_MAX;
        FOR1(i, n) {
            if(mask&(1<<i)) {
                for(lint j=i+1; j<=n; j++) {
                    if(mask&(1<<j)) {
                        lint newmask = (mask & (~(1<<i))) & (~(1<<j));
                        res  = min(res, dist[i][j]+rec(newmask));
                    }
                }
                break;
            }
        }
        dp[mask]=res;
    }
    return dp[mask];
}

int main()
{
    lint t, tst = 1;
    sf1(t);
    while(t--) {
        mem(dp, -1);
        sf2(n,m);
        lint sum=0;

        FOR1(i, n) {
            FOR1(j, n) {
                dist[i][j]=INT_MAX;
            }
        }
        lint flag=0;
        while(m--) {
            lint u, v, c;
            sf3(u,v,c);
            sum+=c;
            flag ^= 1<<u;
            flag ^= 1<<v;
            dist[u][v]=min(dist[u][v], c);
            dist[v][u]=min(dist[v][u], c);
        }
        FOR1(k, n) {
            FOR1(i, n) {
                FOR1(j, n) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
//
//        cout << endl << endl << n << endl << endl;
//        FOR1(i, n) {
//            FOR1(j, n) {
//                cout << dist[i][j] << " ";
//            }
//            cout << endl;
//        }
//
//        FOR1(i, n) {
//            if(flag&(1<<i)) cout << i << " ";
//        }
//        cout << endl;

        lint res = rec(flag);

        pcase(tst++);
        pf1(sum+res);
    }
    return 0;
}
