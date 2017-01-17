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


int main()
{
    int t, tst = 1;
    int m, n;
    sf2(m, n);
    int cnt=0;

    map<string, int> mp;
    string s;
    getline(cin, s);
    FOR(i, m+n) {
        getline(cin, s);
        mp[s]++;
    }

    map<string, int> :: iterator it;

    for(it=mp.begin(); it!=mp.end(); it++) {
        if(it->second == 2) cnt++;
    }

    m-=cnt;
    n-=cnt;

    if(m>n) puts("YES");
    else if(m<n) puts("NO");
    else {
        if(cnt%2==1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
