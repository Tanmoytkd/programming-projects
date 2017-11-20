#include <bits/stdc++.h>
using namespace std;
#define mx 100007

long long n, arr[mx], done, k;

void calculate(long long left, long long diff) {
    for(long long i=0; i<n; i++) {
        long long val = arr[i];
        if(binary_search(arr, arr+n, val+diff)) left--;
        if(!left) {
            printf("%lld %lld\n", val, val+diff);
            return;
        }
    }
}

long long ival(long long diff) {
    long long sum=0;
    for(long long i=0; i<n; i++) {
        long long val=arr[i];
        long long cnt = upper_bound(arr+i, arr+n, val+diff) - (arr+i) - 1;
        sum+=max(cnt, 0LL);
    }
    return sum;
}


int main() {
    while(scanf("%lld%lld", &n, &k)==2) {
        if(n==0 && k==0) break;
        for(long long i=0; i<n; i++) {
            scanf("%lld", &arr[i]);
        }
        sort(arr, arr+n);

        done=0;
        long long l=1, r=arr[n-1]-arr[0], idiff=r;
        while(l<=r) {
            long long mid = (l+r)/2;
            long long idone = ival(mid);
            if(idone>=k) {
                idiff = min(mid, idiff);
                r=mid-1;
            }
            else {
                done = max(done, idone);
                l=mid+1;
            }
        }

        calculate(k-done, idiff);
    }
    return 0;
}
