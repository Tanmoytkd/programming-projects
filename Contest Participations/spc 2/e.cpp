#include <bits/stdc++.h>
using namespace std;



int main()
{

    long long tst;
    long long T[10007],p[10007];
    scanf("%lld", &tst);

    while(tst--) {
        long long m,n,k;
        scanf("%lld%lld%lld", &m, &n, &k);

        for(long long i=0;i<m;i++) {
            scanf("%lld", &T[i]);
        }
        for(long long i=0;i<m;i++) {
            scanf("%lld", &p[i]);
        }
        long long start=0, mid, fin= 10000000000, ans= 10000000000;

        while(start<=fin) {
            mid=(start+fin)/2;

            long long cnt[100000];

            for(long long i=0;i<m;i++) {
                if(mid<T[i])cnt[i]=0;
                else {
                    cnt[i]=1+(mid-T[i])/p[i];
                }
            }

            sort(cnt,cnt+m);

            long long d=m-1, mx=0;
            for(int i=0;i<n;i++)
            {
                mx+=cnt[d];
                d--;
            }
            //cout << mx << endl;

            if(mx>=k) {
                ans=mid;
                fin=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
