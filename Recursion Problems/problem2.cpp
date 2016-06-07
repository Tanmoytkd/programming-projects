#include <bits/stdc++.h>
#define sc scanf
#define pf printf
#define pb push_back

using namespace std;

long long fact (long long n) {
    if(n==1) return 1;
    return n*fact(n-1);
}

int main() {
    long long n, res;

    while(sc("%lld", &n)==1) {
        res=fact(n);
        pf("%lld\n", res);
    }
    return 0;
}
