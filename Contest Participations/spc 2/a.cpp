#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<long long, long long> ok, cost;
    int x=n;
    while(x--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        ok[a]++;
        if(a!=b) cost[b]++;
    }

    long long icost=INT_MAX;

    long long maxcost = (n+1)/2;

    for(auto it=cost.begin(); it!=cost.end(); it++) {
        if(it->second >= maxcost) {
            icost = min(icost, maxcost);
            break;
        }
    }

    for(auto it=ok.begin(); it!=ok.end(); it++) {
        long long int val = it->first;
        long long newcost = maxcost- (it->second);
        //cout << val << " " << it->second << endl;
        if(newcost<=0) {
            icost=0;
            break;
        }
        if(cost[val]>=newcost) icost = min(icost, newcost);
    }

    if(icost==INT_MAX) puts("-1");
    else printf("%lld\n", icost);
    return 0;
}
