#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int num;

void a(int n, int i=1) {
	pf("sin(");
	pf("%d", i);
	if(i!=n) {
		pf("%c", "+-"[i&1]);
		a(n, i+1);
	}
	pf(")");
}

void s(int n, int i=1) {
    if(n==1) {
        a(1);
        pf("+%d", i);
        return;
    }

    pf("(");
    s(n-1, i+1);
    pf(")");
    a(n);
    pf("+%d", i);
}

int main() {
	while(sc("%d", &num)==1) {
		s(num);
		pf("\n");
	}

	return 0;
}
