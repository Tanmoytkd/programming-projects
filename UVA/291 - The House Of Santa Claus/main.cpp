#include <bits/stdc++.h>
#define sc scanf
#define pf printf
#define pb push_back

using namespace std;

vector<int> connect[6];
vector<int> result;
bool check[6][6];

void calc(int i) {
	if(result.size()==9) {
		for(int p=0; p<9; p++) cout << result[p];
		cout << endl;
		return;
	}

	int len=connect[i].size();
	for(int pos=0; pos<len; pos++) {
		int member=connect[i][pos];
		if(!check[i][member]) {
			check[i][member]=true;
			check[member][i]=true;
			result.pb(member);
			calc(member);
			result.pop_back();
			check[member][i]=false;
			check[i][member]=false;
		}
	}
}


int main() {
	connect[1].pb(2);
	connect[1].pb(3);
	connect[1].pb(5);
	connect[2].pb(1);
	connect[2].pb(3);
	connect[2].pb(5);
	connect[3].pb(1);
	connect[3].pb(2);
	connect[3].pb(4);
	connect[3].pb(5);
	connect[4].pb(3);
	connect[4].pb(5);
	connect[5].pb(1);
	connect[5].pb(2);
	connect[5].pb(3);
	connect[5].pb(4);



    result.pb(1);
    calc(1);
    result.pop_back();
    
    return 0;
}
