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
string a, b;
string dp[107][107];

string rec(int x, int y) {
    if(x>=a.size() || y>=b.size()) return "";
    if(dp[x][y]!="*") return dp[x][y];

    string & ret=dp[x][y];
    if(a[x]==b[y]) ret=a[x]+rec(x+1, y+1);
    else {
        string ret1=rec(x+1, y);
        string ret2=rec(x, y+1);
        if(ret1.size()>ret2.size()) ret=ret1;
        else if(ret1.size()<ret2.size()) ret=ret2;
        else ret= (ret1<ret2) ? ret1:ret2;
    }
    return dp[x][y];
}

int main()
{
    int t, tst = 1;
    cin >> t;
    while(t--) {
        FOR(i, 107) {
            FOR(j, 107) {
                dp[i][j]="*";
            }
        }

        cin >> a >> b;
        string res=rec(0,0);
        cout << "Case " << tst++ << ": ";
        if(res.size()>0) cout << res << endl;
        else cout << ":(" << endl;
    }
    return 0;
}
