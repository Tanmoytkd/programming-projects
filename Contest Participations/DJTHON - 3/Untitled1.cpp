#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    long long int ara[100001],i,j,k,n,dif[100001];
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&ara[i]);
    }
    for(i=0;i<n-1;i++){
        dif[i]=abs(ara[i]-ara[i+1]);
    }
    for(i=0;i<n-1;i++){
         printf("%lld ",dif[i]);
    }
}
