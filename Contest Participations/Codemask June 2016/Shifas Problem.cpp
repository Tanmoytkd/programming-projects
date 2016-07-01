#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
#define mod 33554431
using namespace std;

long long shifa[25];

int main() {
    long long twopower=1;
    shifa[0]=1;

    for(int i=1; i<24; i++) {
       twopower<<=1;
       shifa[i]= shifa[i-1]+twopower;
    }

    long long test;
    sc("%lld", &test);
    for(long long t=1; t<=test; t++) {
      long long num;
      sc("%lld", &num);
      pf("Case %lld: ", t);
      pf("%lld\n", shifa[((num%100)%50)%25]);
    }

    return 0;
}
