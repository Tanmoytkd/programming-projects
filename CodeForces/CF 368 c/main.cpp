#include <bits/stdc++.h>

#define pf printf
#define pf1(x) printf("%d\n", x)
#define sf scanf
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)

#define pb push_back
#define Pb pop_back

using namespace std;

int main() {
    #ifdef TKD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    long long n;

    cin >> n;

    if(n<3) pf("-1\n");
    else if(n&1) {
        long long sq=n*n;
        cout << (sq-1)/2 << " " << (sq+1)/2 << endl;
    }
    else {
        long long sq=n*n/2;
        cout << (sq-2)/2 << " " << (sq+2)/2 << endl;
    }

    return 0;
}
