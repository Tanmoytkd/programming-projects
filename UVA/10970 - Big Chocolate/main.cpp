#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int row, col, res1, res2, res;
	while(sc("%d %d", &row, &col)==2) {
		res1=(row-1)+row*(col-1);
		res2=(col-1)+col*(row-1);
		res= (res1<res2) ? res1:res2;
		pf("%d\n", res);
	}
	return 0;	
}