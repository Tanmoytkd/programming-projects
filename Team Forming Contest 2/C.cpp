#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(arr) printf("%d\n",arr)
#define hi() printf("hi!\n")
#define sf scanf
#define sf1(arr) scanf("%d",&arr)
#define sf2(arr,b) scanf("%d %d",&arr,&b)
#define sf3(arr,b,c) scanf("%d %d %d",&arr,&b,&c)
#define sf1ll(arr) scanf("%lld",&arr)
#define sf2ll(arr,b) scanf("%lld %lld",&arr,&b)
#define sf3ll(arr,b,c) scanf("%lld %lld %lld",&arr,&b,&c)
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

#define mx 105000
int arr[mx];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    set<pair<lint, pii> > s;

    lint sum = 0;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    s.insert(make_pair(sum, make_pair(1, n)));
    while( k-- ) {
        set<pair<lint, pii> >::iterator it=s.end();
        it--;
        pair<lint, pii> top = *it;
        cout << top.fs;
        if(k==0) cout << endl;
        else cout << " ";
        s.erase( top );
        int l = top.sc.fs;
        int r = top.sc.sc;
        if( l != r ) {
            s.insert(make_pair(top.fs-arr[l], make_pair(l+1, r)));
            s.insert(make_pair(top.fs-arr[r], make_pair(l, r-1)));
        }
    }
    return 0;
}