#include <bits/stdc++.h>
using namespace std;

long long dp[5007];

int main() {
    char str[5007];
    while(scanf("%s", str)==1) {
        if(str[0]=='0') break;

        int n=strlen(str);
        dp[n]=1;
        if(str[n-1]!='0') dp[n-1]=1;
        else dp[n-1]=0;

        for(int pos=n-2; pos>=0; pos--) {
            if(str[pos]=='0') {
                dp[pos]=0;
                continue;
            }
            dp[pos]=dp[pos+1];
            int dig=str[pos]-'0';
            dig*=10;
            dig+=str[pos+1]-'0';
            if(dig<=26) dp[pos]+=dp[pos+2];
        }
        printf("%lld\n", dp[0]);
    }
    return 0;
}
