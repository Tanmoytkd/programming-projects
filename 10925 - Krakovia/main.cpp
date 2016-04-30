#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef TKD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    int i=0;
    int n, f;

    while(scanf("%d %d", &n, &f)==2) {
        if(n==0 && f==0) break;
        i++;

        unsigned long long sum=0, num;

        for(int i=0; i<n; i++) {
            scanf("%llu", &num);
            sum+=num;
        }

        printf("Bill #%d costs %llu: each friend should pay ", i, sum);
        sum/=f;
        printf("%llu\n\n", sum);
    }

    return 0;
}
