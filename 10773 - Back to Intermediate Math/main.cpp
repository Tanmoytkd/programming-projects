#include <bits/stdc++.h>

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
        double d, v, u;
        cin >> d >> v >> u;

        if(v==0 || u==0 || u<=v) {
            cout << "Case " << i << ": can't determine" << endl;
            continue;
        }

        double small=d/u, large=sqrt(d*d/(u*u-v*v)), res=large-small;

        cout << "Case " << i << ": " << fixed << setprecision(3) << res << endl;
    }

    return 0;
}
