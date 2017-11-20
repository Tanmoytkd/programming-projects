#include <bits/stdc++.h>
using namespace std;

struct data {
    long double a, b, c;
    data(long double a, long double b, long double c) :a(a), b(b), c(c) {}
    data(): a(), b(), c() {}
    bool operator==(data x) {
        return (a==x.a && b==x.b && c==x.c);
    }
    data operator+(data x) {
        return {a+x.a, b+x.b, c+x.c};
    }
    data operator*(long double f) {
        return {a*f, b*f, c*f};
    }
} dp[101][101][101];

data go(long long r, long long s, long long p) {
    if(r==0 && s==0 && p==0) return {0,0,0};
    if(r!=0 && s==0 && p==0) return {1,0,0};
    if(r==0 && s!=0 && p==0) return {0,1,0};
    if(r==0 && s==0 && p!=0) return {0,0,1};
    if(r==0) return {0,1,0};
    if(s==0) return {0,0,1};
    if(p==0) return {1,0,0};
    if(r==s && s==p) return {1.00/3, 1.00/3, 1.00/3};

    if(dp[r][s][p]==data()) {
        long long total=r+s+p;
        long long up=(r*(r-1)/2)+(s*(s-1)/2)+(p*(p-1)/2);
        long long down=total*(total-1)/2;
        up=down-up;
        long double mul= down*1.00/up;

        //cout << r << " " << s << " " << p << " " << mul.up << "/" << mul.down << endl;

        long double f1(r*s*1.00/down), f2(s*p*1.00/down), f3(p*r*1.00/down);
        f1=f1*mul;
        f2=f2*mul;
        f3=f3*mul;

        dp[r][s][p]=go(r, s-1, p)*f1 + go(r,s,p-1)*f2 + go(r-1, s, p)*f3;
    }
    return dp[r][s][p];
}

int main() {
    long long int r, s, p;
    cin >> r >> s >> p;

    data res = go(r, s, p);

    cout << fixed << setprecision(12);
    cout << res.a << " ";
    cout << res.b << " ";
    cout << res.c << endl;
    return 0;
}
