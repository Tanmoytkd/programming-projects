#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //for(int n=2147483647; n<=2147483647; n++) {
        int n=2147483647;
        long long res = 0;
        for(long long pow=5; pow<=n; pow*=5) {
            res += floor(n/pow);
            //cout << res << endl;
        }
        cout << n << "             " << res << endl;
    //}

    return 0;
}
