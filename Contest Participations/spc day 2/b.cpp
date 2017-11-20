/*input


    2

    2 3

    2 3 8

    5 2 7

    2 3

    1 2 3

    3 2 1

*/
#include<bits/stdc++.h>
#define pii pair<lint,lint>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%lld\n",a)
#define hi() printf("hi!\n")
#define sf scanf
#define sf1(a) scanf("%lld",&a)
#define sf2(a,b) scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
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


int main()
{
    lint t, tst = 1;
    cin >> t;
    while(t--) {
    	lint m, n;
    	cin >>m >> n;

    	lint res=0;
    	std::vector<lint> v;
    	FOR(i, m) {
    		v.pb(0);
    		FOR(j,n) {
    			lint num;
    			cin >> num;
    			v.back()+=num;
    		}
    		res^=v.back();
    	}
    	pcase(tst++);
    	if(res) cout << "Alice" << endl;
    	else cout << "Bob" << endl;
    }
    
    return 0;
}
