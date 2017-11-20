#include <bits/stdc++.h>
#define sc scanf
#define pf printf
#define pb push_back

using namespace std;

int main() {
    unsigned int t, n;
    cin >> t;
    for(unsigned int test=1; test<=t; test++) {
        cin >> n;
        int pos=1, power=0;
        for(pos=1; pos<=32; pos++) {
            int a = (n&(1<<pos)), b = (n&(1<<pos-1))>0;
            if(!a && b) {
                //cout << "tkd" << endl;
                n>>=pos;
                //cout << n << endl;
                n++;
                //cout << n << endl;
                n<<=pos;
                //cout << n << endl;
                break;
            }
            else if(b) power++;
        }
        //cout << "power " << power << endl;
        n+= (1<<power)-1;
        pf("Case %d: %d\n", test, n);
    }

    return 0;
}
