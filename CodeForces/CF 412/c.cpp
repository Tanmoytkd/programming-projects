#include <bits/stdc++.h>
using namespace std;

struct data {
    long long x, y;
    data() {
        x=0,y=0;
    }
    data(long long x, long long y):x(x), y(y) {}
};



data extendedEuclid(long long a, long long b) {
  if(b == 0) return data(1, 0);
  else {
    data d = extendedEuclid(b, a % b);
    return data(d.y, d.x - d.y * (a / b));
  }
}

int possible(long long a, long long b, long long c) {
    return (c%__gcd(a,b)==0);
}


int main() {
//    data z = extendedEuclid(4, 2);
//    cout << z.x << " " << z.y << endl;
    int t;
    cin >> t;

    while(t--) {
        long long x, y, p, q;
        cin >> x >> y >> p >> q;

        long long x1=p-q, y1=p, c=q*x-p*y;
        if(possible(x1, y1, c)) {
            long long gcd=__gcd(x1,y1);
            long long mul = c/gcd;
            data calc = extendedEuclid(x1, y1);

            long long a=calc.x, b=calc.y;
            //cout << a*mul << "*" << x1 << "+" << b*mul << "*" << y1 << endl;

//            long long res= LLONG_MAX;
//
//            long long lowlim=(y1==0)? 0: ceil(-a/y1), uplim=(x1==0)? 0: floor(b/x1);
//
//            if(lowlim>uplim) {
//                cout << -1 << endl;
//                continue;
//            }
//            else {
//                for(long long t=lowlim; t<=uplim; t++) {
//                    long long newres=a+y1*t+b-x1*t;
//                    if(newres<=res) res=newres;
//                    else break;
//                }
//            }
            long long res = mul*(calc.x + calc.y);
            int diff=x1-y1;

            res%=diff;


            cout << res << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}
