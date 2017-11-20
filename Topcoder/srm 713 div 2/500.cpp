#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

class PowerEquationEasy {
public:
	int count(int);
};

long long calculate(long long n) {
    long long res = (n*n)%mod;
    long long sq = sqrt(n);
    long double lgn = log(n);
    for(long long i=2; i<=sq; i++) {
        long long lg = lgn / log(i);
        cout << i << " " << lg << endl;
        res += lg*(lg+1)/2;
        res%=mod;
        res += (n-lg)*lg;
        res%=mod;
    }
    res+= ((n-sq)*n)%mod;
    res%=mod;
    return res;
}

int PowerEquationEasy::count(int n) {
    long long res = calculate(n);
    return int(res);
}

#ifdef TKD
int main() {
    int n;
    cin >> n;
    PowerEquationEasy p;
    cout << p.count(n) << endl;
    return 0;
}
#endif // TKD
