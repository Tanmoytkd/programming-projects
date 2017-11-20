#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi() printf("hi!\n")
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
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
	ios_base::sync_with_stdio(false);
    int t, tst = 0;
    // cin >> t;
    sf1(t);

    while(t--) {
    	++tst;
    	int n;
    	// cin >> n;
    	sf1(n);
    	map <string, int> mp;
    	for(int i=0; i<n; i++) {
    		char s[105];
    		sf("%s", s);
    		// cin >> s;
    		int len=strlen(s);
    		if(len>2) sort(s+1, s+len-1);

    		mp[s]++;
    	}

    	int m;
    	sf1(m);

    	// cin >> m;
    	printf("Case %d:\n", tst);

    	//cout << "Case " << tst << ":" << endl;

    	char str[10007];
    	gets(str);
    	//puts(str);
    	while(m--) {
    		gets(str);
    		//puts(str);
    		// getline(cin, str);

    		istringstream ss(str);

    		long long res=1;

    		string st;
    		while(ss >> st) {
    			
    			if(st.size()>2) sort(st.begin()+1, st.end()-1);
    			//cout << st << " " << mp[st] << endl;

    			res*= mp[st];
    		}

    		pf("%lld\n", res);
    		// cout << res << endl;
    	}

    }
    
    return 0;
}