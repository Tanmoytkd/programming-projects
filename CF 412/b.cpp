#include <bits/stdc++.h>
using namespace std;

long long check(long long int s, long long int pos) {
    long long i= (s/50)%475;
    long long cnt=25;
    while(cnt--) {
        i=(i*96+42)%475;
        if((i+26)==pos) return 1;
    }
    return 0;
}

int main() {
    long long int p, x, y;
    cin >> p >> x >> y;

    long long res=0;
    while(x<y) {
        x+=100;
        res++;
    }

    long long temp=x;
    while(temp>=y) {
        if(check(temp, p)) {
            cout << res << endl;
            return 0;
        }
        temp-=50;
    }
    while(1) {
        x+=50;
        res++;

        if(check(x, p)) {
            cout << res << endl;
            return 0;
        }

        x+=50;

        if(check(x, p)) {
            cout << res << endl;
            return 0;
        }

    }
    return 0;
}
