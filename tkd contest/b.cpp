#include <bits/stdc++.h>
using namespace std;

long long dp[100007];

int main() {
    long long n;
    while(scanf("%lld", &n)==1) {
        if(n==-1) break;
        memset(dp, 0, sizeof dp);
        long long start[n+1], fin[n+1];
        vector<pair<long, long> > v;

        for(long long i=0; i<n; i++) {
            long long s, f;
            scanf("%lld %lld", &s, &f);
            v.push_back(make_pair(s,f));
        }

        sort(v.begin(), v.end());
        for(int i=0; i<n; i++) {
            start[i]=v[i].first;
        }
        dp[n-1]=1;

        for(int pos=n-2; pos>=0; pos--) {
            dp[pos]=dp[pos+1]+1;
            long long f=v[pos].second;

            int newpos=lower_bound(start, start+n, f)-start;
            if(newpos!=n) {
                dp[pos]+=dp[newpos];
            }
            dp[pos]%=100000000;
        }

//        for(int i=0; i<n; i++) {
//            printf("%08lld\n", dp[i]);
//        }
        printf("%08lld\n", dp[0]);
    }

    return 0;
}
