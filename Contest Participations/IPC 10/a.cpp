#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;

int dp[3403][12881];
int n, m, weight[3403], desire[3403];

int rec(int pos, int sackspace) {
    if(pos==n) return 0;
    if(dp[pos][sackspace]==-1) {
        if(weight[pos]<=sackspace)
            dp[pos][sackspace] = desire[pos] + rec(pos+1, sackspace-weight[pos]);

        dp[pos][sackspace] = max(dp[pos][sackspace], rec(pos+1, sackspace));
    }
}

int main() {
    memset(dp, -1, sizeof dp);

    scanf("%d%d", &n, &m);

    for(int i=0; i<n; i++) {
        scanf("%d%d", &weight[i], &desire[i]);
    }

    printf("%d\n", rec(0, m));
}
