#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fs first
#define sc second


int between(pii p1, pii p2, pii p3) {
    int x1=p2.fs, x2=p3.fs, y1=p2.sc, y2=p3.sc;
    if(x1>x2) swap(x1, x2);
    if(y1>y2) swap(y1, y2);

    if(p1.fs>=x1 && p1.fs<=x2 && p1.sc >= y1 && p1.sc <= y2) return 1;
    else return 0;

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x11, y11, x12, y12, x21, y21, x22, y22;
        cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;

        int one, two;
        if(x11==x12 && y11==y12) one=0;
        else if(x11==x12) one=1;
        else one=2;

        if(x21==x22 && y21==y22) two=0;
        else if(x21==x22) two=1;
        else two=2;

        pair<int, int> p1(x11, y11), p2(x12, y12), p3(x21, y21), p4(x22, y22);

        if(p1>p2) swap(p1, p2);
        if(p3>p4) swap(p3, p4);

        if(one==0) one=two;
        if(two==0) two=one;

        if(one==two) {
            if(between(p1, p3, p4) || between(p2, p3, p4) || between(p3, p1, p2) || between(p4, p1, p2)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else {
            if(p1==p3 || p1==p4 || p2==p3 || p2==p4) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}
