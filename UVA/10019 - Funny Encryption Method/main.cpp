#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int test;
    cin >> test;

    for(int i=1; i<=test; i++) {
        int num;
        cin >> num;

        int x=num, countbin=0;
        while(x>0) {
            if(x&1) countbin++;
            x>>=1;
        }
        cout << countbin << " ";

        int y=num, counthex=0;
        while(y>0) {
            int dig=y%10;
            y/=10;
            while(dig>0) {
                if(dig&1) counthex++;
                dig>>=1;
            }
        }

        cout << counthex << endl;
    }

    return 0;
}
