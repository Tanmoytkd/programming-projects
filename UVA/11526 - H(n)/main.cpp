#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

long long num, sqt;

long long H(long long i, long long n) {
	if(i==n) return n;
	if(i>n) return 0;
	if(i>sqt) return 0;

	long long newnum=num/(i+1);
	return n+i*(n-newnum)+ H(i+1, newnum);

}

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    long long t;
    cin >> t;
    while(t--) {
        long long res;
        cin >> num;
        sqt=sqrt(num);
        res=H(1, num);
        cout << res << endl;
    }

    return 0;
}
