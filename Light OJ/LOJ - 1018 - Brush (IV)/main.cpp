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
int n, dp[1<<18];
vector<pii> v;
int rec(int mask, int level) {
    if(__builtin_popcount(mask)==n) return 0;
    if(dp[mask]==-1) {
        int res=INT_MAX;
        for(int i=0; i<n; i++) {
//            cout << "i = " << i << endl;
//            cout << "tkd" << endl;
//            cout << mask << endl;
//            cout << "level = " << level << endl;
            if(mask&(1<<i)) {
                continue;
            }
            int newmask1=mask|(1<<i);
            res=min(res, 1+rec(newmask1, level+1));

            for(int j=i+1; j<n; j++) {
//                cout << "j = " << j << endl;

                if(mask&(1<<j)) {
                    continue;
                }
                int newmask = newmask1;
                newmask |= (1<<j);
                int up=v[j].second-v[i].second;
                int down=v[j].first-v[i].first;


                for(int k=j+1; k<n; k++) {
                    if(mask&(1<<k)) {
                        continue;
                    }
//                    cout << "k = " << k << endl;

                    int up1=v[k].second - v[i].second;
                    int down1=v[k].first - v[i].first;

                    int sameline=0;
                    if(down==0 && down1==0) sameline=1;
                    else if(up==0 && up1==0) sameline=1;
                    else if(up*down1 == up1*down) sameline=1;

                    if(sameline) {
                        newmask |= (1<< k);
                    }
                }
                res=min(res, 1+rec(newmask, level+1));
            }
            break;
        }
        dp[mask]=res;
    }
    return dp[mask];
}

int main()
{
    int t, tst = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        v.clear();
        for(int i=0; i<n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            v.push_back(pii(x,y));
        }

        memset(dp, -1, sizeof dp);
        int res=rec(0, 0);
        printf("Case %d: %d\n", tst++, res);
    }
    return 0;
}
