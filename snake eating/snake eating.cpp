#include <bits/stdc++.h>
using namespace std;
#define lint long long

lint arr[1000007], cum[1000007], k, pos, n, q;

lint val(int p) {
    if(p<0) return 0;
    if(p>=n) return cum[n-1];
    return cum[p];
}

lint valid(lint mid) {
    lint elements=pos-mid;
    lint needed = k*elements - (val(pos-1)-val(mid-1));
    if(needed<=mid) return 1;
    return 0;
}

int main() {
    lint t;
    cin >> t;

    while(t--) {
        cin >> n >> q;

        for(lint i=0; i<n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);

        cum[0]=arr[0];
        for(lint i=1; i<n; i++) {
            cum[i]=cum[i-1]+arr[i];
        }

        while(q--) {

            cin >> k;

            pos=lower_bound(arr, arr+n, k)-arr;
            long long res = n-pos;
            pos;
            lint l=0, r=pos-1, mid, ans=0;
            while(l<=r) {
                mid=(l+r)/2;
                if(valid(mid)) {
                    ans=max(ans, pos-mid);
                    r=mid-1;
                }
                else l=mid+1;
            }
            cout << ans+res << endl;
        }
    }
    return 0;
}
