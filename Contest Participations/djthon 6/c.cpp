#include <bits/stdc++.h>
using namespace std;

struct frac {
    long long int up, down;

    void purify() {
        long long gcd=__gcd(up, down);
        if(gcd!=0) {
            up/=gcd;
            down/=gcd;
        }
        if(down<0) {
            up=-up;
            down=-down;
        }
    }

    frac() {
        up=0,down=1;
    }
    frac(long long int up, long long int down) :up(up), down(down) {
        purify();
    }

    bool operator== (frac b) {
        return (up==b.up && down==b.down);
    }
    friend frac operator+ (frac a, frac b);
    friend bool operator< (frac a, frac b);
};

frac operator+ (frac a, frac b) {
    long long down=a.down/__gcd(a.down, b.down)*b.down;
    long long up=a.up*(down/a.down)+b.up*(down/b.down);

    return frac(up, down);
}

frac operator* (frac x, frac y) {
    long long a=x.up, b=x.down, c=y.up, d=y.down;
    long long gcd=__gcd(a,d);
    if(gcd!=0) {
        a/=gcd;
        d/=gcd;
    }
    gcd=__gcd(b,c);
    if(gcd!=0) {
        b/=gcd;
        c/=gcd;
    }
    return frac(a*c, b*d);
}

bool operator< (frac a, frac b) {
    return a.up*b.down < b.up*a.down;
}

struct data {
    frac a, b, c;
    data(frac a, frac b, frac c) :a(a), b(b), c(c) {}
    data(): a(), b(), c() {}
    bool operator==(data x) {
        return (a==x.a && b==x.b && c==x.c);
    }
    data operator+(data x) {
        return {a+x.a, b+x.b, c+x.c};
    }
    data operator*(frac f) {
        return {a*f, b*f, c*f};
    }
} dp[101][101][101];

data go(long long r, long long s, long long p) {
    if(r==0 && s==0 && p==0) return {{0,1},{0,1},{0,1}};
    if(r!=0 && s==0 && p==0) return {{1,1},{0,1},{0,1}};
    if(r==0 && s!=0 && p==0) return {{0,1},{1,1},{0,1}};
    if(r==0 && s==0 && p!=0) return {{0,1},{0,1},{1,1}};
    if(r==0) return {{0,1},{1,1},{0,1}};
    if(s==0) return {{0,1},{0,1},{1,1}};
    if(p==0) return {{1,1},{0,1},{0,1}};
    if(r==s && s==p) return {{1,3},{1,3},{1,3}};

    if(dp[r][s][p]==data()) {
        long long total=r+s+p;
        long long up=(r*(r-1)/2)+(s*(s-1)/2)+(p*(p-1)/2);
        long long down=total*(total-1)/2;
        up=down-up;
        frac mul= frac(down, up);

        //cout << r << " " << s << " " << p << " " << mul.up << "/" << mul.down << endl;

        frac f1(r*s, down), f2(s*p, down), f3(p*r, down);
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
    cout << res.a.up*1.00/res.a.down << " ";
    cout << res.b.up*1.00/res.b.down << " ";
    cout << res.c.up*1.00/res.c.down << endl;
    return 0;
}
