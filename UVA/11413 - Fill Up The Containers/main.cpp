/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int n, m;
    while(sf2(n,m)!=EOF) {
        int arr[n];
        int low=-999, high=0;
        FOR(i, n) {
            sf1(arr[i]);
            low=(arr[i]>low) ? arr[i]:low;
            high+=arr[i];
        }

        int total=high;

        while(low<high) {
            int mid=(low+high)/2;
            int sum=0, t=total, j=0;
            FOR(i, m) {
                sum=0;
                for(; j<n && sum+arr[j]<=mid; j++) {
                    t-=arr[j];
                    sum+=arr[j];
                }
            }
            if(t==0) high=mid;
            else low=mid+1;
        }

        pf1(low);
    }
    return 0;
}
