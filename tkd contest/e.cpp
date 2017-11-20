#include <bits/stdc++.h>
using namespace std;

int cnt[1007];

int val(int pos) {
    if(pos<0) return 0;
    if(pos>1000) return cnt[1005];
    return cnt[pos];
}

int main() {
    memset(cnt, 0, sizeof cnt);
    int n;
    cin >> n;
    int T;
    for(int i=0; i<n; i++) {
        int ti;
        cin >> ti;
        cnt[ti]++;
    }
    cin >> T;

    for(int i=1; i<1007; i++) {
        cnt[i]+=cnt[i-1];
    }

    int res=0;
    for(int i=0; i<=1000; i++) {
        res=max(res, val(i+T)-val(i-1) );
    }

    cout << res << endl;

    return 0;
}
