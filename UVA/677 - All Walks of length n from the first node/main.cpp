#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int data[12][12], n, len, check[12], counter=0;
std::vector<int> v;

void rec(int node) {
    if(!check[node]) {
        check[node]=1;
        v.pb(node);

        if(v.size()==len) {
            counter++;
            pf("(");
            for(int i=0; i<len; i++) {
                pf("%d", v[i]);
                pf("%c", ",)"[i==len-1]);
            }
            pf("\n");
        }
        else {
            for(int pos=1; pos<=n; pos++) {
                if(data[node][pos]) rec(pos);
            }
        }

        v.Pb();
        check[node]=0;
    }
}

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int divider, first=1;
	while(sc("%d %d", &n, &len)==2) {
        counter=0;
        len++;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				cin >> data[i][j];
			}
		}

		if(!first) cout << endl;
		else first=0;

		rec(1);

		if(counter==0) pf("no walk of length %d\n", len-1);

        if(sc("%d", &divider)!=1) break;
	}

	return 0;
}
