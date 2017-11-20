/*input
10
1 2 3 4 5 6 7 8 9 10
*/

#include <bits/stdc++.h>
using namespace std;
/*
1 0
3 0
4 1
15 1
16 2
81 2
82 0
6723 0
6724 3
50625 3
50626 1
1000000 1
*/
int dp[1000010];

int grundy(long long num) {
    dp[1]=0;
    dp[3]=0;
    dp[4]=1;
    dp[15]=1;
    dp[16]=2;
    dp[81]=2;
    dp[82]=0;
    dp[6723]=0;
    dp[6724]=3;
    dp[50625]=3;
    dp[50626]=1;
    dp[1000000]=1;
    vector<long long int> v = {1,3,4,15,16,81,82,6723,6724,50625,50626,1000000};
    if(num<=1000000) {
        int pos = lower_bound(v.begin(), v.end(), num)-v.begin();
        num = v[pos];
        return dp[num];
    }

    set<int> x;

    long double sq = sqrt(num), ssq=sqrt(sq);
    long long start = ceil(ssq);
    int pos = lower_bound(v.begin(), v.end(), start) - v.begin();
    while(pos<v.size()) {
        long long val = v[pos];
        if(val>sq) break;
        x.insert(dp[val]);
        pos++;
    }

    int ret=0;
    while(x.count(ret)) ret++;
    return ret;
}

int main() {
    int n;
    cin >> n;
    long long arr[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        arr[i]=grundy(arr[i]);
    }
    long long res =0;
    for(int i=0; i<n; i++) {
        res^=arr[i];
    }

    if(res==0) cout << "Rublo" << endl;
    else cout << "Furlo" << endl;
//    int x = 3;
//    cin >> x;
//    cout << "number is " << x << " : grundy is " << calculate(x) << endl;
    return 0;
}
