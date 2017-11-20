#include <bits/stdc++.h>
using namespace std;
#define mx 10000000

int dp[10000007];

void seive() {
    dp[0]=0;
    dp[1]=1;
    for(int i=4; i<=mx; i+=2) dp[i]=1;
    int stop=sqrt(mx);
    for(int i=3; i<=stop; i+=2) {
        if(dp[i]) continue;
        for(int j=i*i; j<=mx; j+=i+i) dp[j]=1;
    }
}

int main() {
    seive();
    for(int i=2; i<=mx; i++) {
        dp[i]+=dp[i-1];
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int num;
        scanf("%d", &num);

        printf("%d\n", num-1-dp[num-1]);
    }
    return 0;
}
