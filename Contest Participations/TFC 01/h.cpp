#include <bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define right() printf("right!\n")
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(fibo) printf("Case %d: ",fibo)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,fibo) memset((arr), (fibo), sizeof((arr)));
#define FOR(i,fibo) for(int i=0;i<(fibo); i++)
#define FOR1(i, fibo) for(int i = 1; i<=fibo ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
#define mx 1000007

int cnt[105], fibo[mx];

int done(int k) {
	for (int i = 1; i <= k; i++) {
		if (cnt[i] <= 0)
			return false;
	}
	return true;
}

int main() {
	int n, m, k, t, count = 0;

	scanf("%d", &t);

	while (t--) {
		count++;
		sf3(n,m,k);

		fibo[0] = 1;
		fibo[1] = 2;
		fibo[2] = 3;

		for (int i = 3; i < n; i++) {
			fibo[i] = (fibo[i - 1] + fibo[i - 2] + fibo[i - 3]) % m + 1;
		}

		for (int i = 0; i < 105; i++)
			cnt[i] = 0;
		int left = 0, right = 0, res = 1000005;
		cnt[fibo[right]]++;

		while (true) {
			if (done(k)) {
				if ((right - left + 1) < res)
					res = right - left + 1;
				if (fibo[left] <= k)
					cnt[fibo[left]]--;
				left++;
			} 
			else {
				right++;
				if (right < n) {
					if (fibo[right] <= k)
						cnt[fibo[right]]++;
				} 
				else {
					break;
				}
			}
		}

		printf("Case %d: ", count);
		if (res == 1000005)
			printf("sequence nai\n");
		else
			printf("%d\n", res);
	}

	return 0;
}