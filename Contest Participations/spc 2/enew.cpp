#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,k,t;
    long long T[10005],p[10005];
    cin>>t;
    while(t--)
    {
        cin>>m>>n>>k;
        for(int i=0;i<m;i++) {
            cin>>T[i];
        }
        for(int i=0;i<m;i++) {
            cin>>p[i];
        }

        long long start=0,mid, fin=10000000000, ans=10000000000;

        while(start<=fin) {
            mid=(start+fin)/2;

            long long cnt[10007];

            for(int i=0;i<m;i++) {
                if(mid<T[i])cnt[i]=0;
                else cnt[i]=1+(mid-T[i])/p[i];
            }

            sort(cnt,cnt+m);

            long long pos=m-1, mxnut=0;
            for(int i=0;i<n;i++) {
                mxnut+=cnt[pos];
                pos--;
            }

            if(mxnut>=k) {
                ans=mid;
                fin=mid-1;
            }
            else start=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
