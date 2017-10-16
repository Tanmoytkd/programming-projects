/*
ID: tanmoyk2
PROG: subset
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf prlong longf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) prlong longf("%d\n", x)
#define PI acos(-1.00)
#define FOR(I, N) for(I=0; I<N; I++)
#define FOR1(I, N) for(I=1; I<=N; I++)

using namespace std;

long long n;
long long arr[100];

long long dp[40][2000];

long long go(long long pos, long long sum) {
	if(pos==n) {
		if(sum==0) return 1;
		else return 0;
	}

	long long & ret = dp[pos][sum+1000]; 
	if(ret==-1) {
		ret=0;
		ret+=go(pos+1, sum+arr[pos]);
		ret+=go(pos+1, sum-arr[pos]);
	}
	return ret;
}
int main() {
    

    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    memset(dp, -1, sizeof dp);

    cin >> n;

    if(n==1) {
    	cout << 0 << endl;
    	return 0;
    }
    for(long long i=0; i<n; i++) {
    	arr[i]=i+1;
    }

    long long res=go(1, arr[0]);
    res+=go(1, 0-arr[0]);

    cout << (res/2) << endl;

    return 0;
}
