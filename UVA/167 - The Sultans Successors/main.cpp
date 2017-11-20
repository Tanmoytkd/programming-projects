#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int board[9][9], check[9], maxi=0;
std::vector<int> v, value;

void rec(int col=0) {
	if(col==8) {
		int sum=0;
//		for(int i=0; i<8; i++) cout << v[i] << " ";
//		cout << endl;
		for(int i=0; i<8; i++) sum+=value[i];
		if(sum>maxi) maxi=sum;
		return;
	}

	for(int i=0; i<8; i++) {
		if(check[i]) continue;
		int len=v.size(), diff1, diff2, conflict=0;
		for(int pos=0; pos<len; pos++) {
			diff1=abs(v[pos]-i);
			diff2=abs(pos-col);
			if(diff1==diff2) {
                conflict=1;
                break;
			}
		}
		if(conflict) continue;

		check[i]=1;
		v.pb(i);
		value.pb(board[i][col]);
		rec(col+1);
		value.Pb();
		v.Pb();
		check[i]=0;
	}
}

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int k;
	cin >> k;

	while(k--) {
		for(int i=0; i<8; i++) {
			for(int j=0; j<8; j++) {
				int num;
				sc("%d", &num);
				board[i][j]=num;
			}
		}

		maxi=0;
		rec(0);

		pf("%5d\n", maxi);
	}
	return 0;
}
