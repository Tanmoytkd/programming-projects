#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[1007];
char dp[1007][1007];
set<int> res;

void rec(int pos, int coin, int sum) {
    if(pos==k) {
        res.insert(sum);
        return;
    }
    if(coin==n) return;
    if(dp[pos][coin]) return;



    int left = k-pos;

    for(int i=0; i<=left; i++) {
        rec(pos+i, coin+1, sum+i*arr[coin]);
    }
}

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    rec(0, 0, 0);

    for(auto it=res.begin(); it!=res.end(); it++) {
        if(it!=res.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;
    return 0;
}
