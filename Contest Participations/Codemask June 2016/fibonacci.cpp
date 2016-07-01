#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
#define MXN 108
using namespace std;

int fibo[MXN];
int Gata[30];

int fib(long long n) {
    return fibo[n%MXN];
}

int G(long long n) {
    if(n==0) return 0;

    return (G(n-1)+fib(4*n-1))%1007;
}

int main() {
    fibo[0]=0;
    fibo[1]=1;

	for(int i=2; i<MXN; i++) {
		fibo[i]=(fibo[i-1]+fibo[i-2])%1007;
	}

	Gata[0]=G(0);
	for(long long i=1; i<30; i++)
        Gata[i]=max(G(i), Gata[i-1]);

    int t;
    cin >> t;
    while(t--) {
        long long num;
        cin >> num;
        if(num>=30) cout << Gata[29] << endl;
        else cout << Gata[num] << endl;
    }

	return 0;
}
