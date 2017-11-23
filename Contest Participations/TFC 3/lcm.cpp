#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

long long lcm(long long a, long long b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    long long n;
    cin >> n;
    long long ans = LLONG_MIN;

    
    for(long long i = max(n-50,1LL);i<=n; i++) {
        for(long long j=i; j<=n; j++) {
            for(long long k=j; k<=n; k++) {
                long long x = lcm(lcm(i,j),k);
                ans = max(ans,x);
            }
        }
    }

    cout << ans << endl;

    return 0;
}