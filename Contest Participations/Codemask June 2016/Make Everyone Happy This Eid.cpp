#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

vector<int> check [835][835];
int total=0, n, coin[50];

int rec(int pos, int a, int b) {
    if(a==0 && b==0)  {
        return 1;
    }
    if(find(check[a][b].begin(), check[a][b].end(), pos)!= check[a][b].end()) return 1;
    if(pos==n) return 0;

    int res1=0, res2=0, res3=0;
    if(a>=coin[pos]) res1=rec(pos+1, a-coin[pos], b);
    if(b>=coin[pos]) res2=rec(pos+1, a, b-coin[pos]);
    res3=rec(pos+1, a, b);


    int res = res1 || res2 || res3;
    if(res) check[a][b].pb(pos);
    return res;


}

int main() {

	int test;
	sc("%d", &test);
	for(int t=1; t<=test; t++)  {
        for(int i=0; i<835; i++) {
            for(int j=0; j<835; j++) {
                check[i][j].clear();
            }
        }
		int happy=1;

		total=0;
		sc("%d", &n);

		for(int i=0; i<n; i++) {
			sc("%d", &coin[i]);
			total+=coin[i];
		}

		if(total%3==0) {
			happy= rec(0, total/3, total/3);
		}



		pf("Case %d: ", t);
		if(happy) pf("Eid Makes Happy Everyone\n");
		else pf(":(\n");
	}
	return 0;
}
