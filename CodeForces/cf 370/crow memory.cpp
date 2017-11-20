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

using namespace std;

int main() {
    int n;
    sf1(n);

    int arr[n+1];
    for(int i=0; i<n; i++) {
        sf1(arr[i]);
    }
    arr[n]=0;

    for(int i=0; i<n; i++) {
        arr[i]+=arr[i+1];
    }

    for(int i=0; i<n; i++) {
        pf("%d%c", arr[i], " \n"[i==n-1]);
    }

    return 0;
}
