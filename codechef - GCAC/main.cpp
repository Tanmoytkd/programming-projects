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

int n, m;
long long minsal[1007];
long long offsal[1007], maxjob[1007];

int main()
{
    int t, tst = 1;
    sf1(t);

    while(t--) {
    	sf2(n,m);

    	
    	for(int i=0; i<n; i++) sf1ll(minsal[i]);

    	
    	for(int i=0; i<m; i++) {
    		sf2ll(offsal[i], maxjob[i]);
    	}

    	int ind[m];
    	for(int i=0; i<m; i++) ind[i]=i;

    	sort(ind, ind+m, [](int i, int j) {return offsal[i]>offsal[j];});

    	char arr[1010][1010];
    	for(int i=0; i<n; i++) {
    		scanf("%s", arr[i]);
    	}

    	long long lucky=0, totalsalary=0, zeroemp=0, cntemp[m];
    	memset(cntemp, 0, sizeof cntemp);
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<m; j++) {
    			int cmp=ind[j];
    			if(cntemp[cmp]<maxjob[cmp] && offsal[cmp]>=minsal[i] && arr[i][cmp]>'0') {
    				cntemp[cmp]++;
    				lucky++;
    				totalsalary+=offsal[cmp];
    				//cout << "Person " << i << ": " << cmp << endl;
    				break;
    			}
    		}
    	}

    	for(int i=0; i<m; i++) if(cntemp[i]==0) zeroemp++;

    	pf("%lld %lld %lld\n", lucky, totalsalary, zeroemp);

    }
    return 0;
}