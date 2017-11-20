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
#define sf1(a) sf("%d",&a)
#define sf2(a,b) sf("%d %d",&a,&b)
#define sf3(a,b,c) sf("%d %d %d",&a,&b,&c)
#define sf1ll(a) sf("%I64d",&a)
#define sf2ll(a,b) sf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) sf("%I64d %I64d %I64d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
using namespace std;
typedef long long int lint;
typedef double dbl;

int main() {
	int N;
	sf("%d", &N);
	vector<lint> A(N);
	FOR(i, N) sf("%lld", &A[i]);
	sort(A.begin(), A.end());
	vector<lint> sum(N+1, 0);
	FOR(i, N) {
        sum[i+1] = sum[i] + A[i];
	}

	int Q;
	sf("%d", &Q);
	lint added = 0;
	FOR(ii, Q) {
		int x;
		sf("%d", &x);
		added += x;
		int k = lower_bound(A.begin(),A.end(), -added) - A.begin();
		lint ans = 0;
		ans += (sum[N] - sum[k]) + added * (N - k);
		ans += -((sum[k] - sum[0]) + added * k);
		printf("%lld\n", ans);
	}
	return 0;
}
