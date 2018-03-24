#include <bits/stdc++.h>
using namespace std;

std::vector<int> chain[55];

int dp[55][107][107];

int grundy(int pos, int start, int finish) {

	int & ret = dp[pos][start][finish];
	if(ret==-1) {

		std::vector<int>& c = chain[pos];
		

		int allsame=1;
		for(int i=start; i<=finish; i++) {
			if(c[i]!=c[start]) allsame=0;
		}
		if(allsame) {
			ret=1;
			return ret;
		}

		set<int> s;

		
		for(int i=start; i<=finish; i++) {
			int val = c[i];

			int gd = 0;
			for(int newstart=start; newstart<=finish; newstart++) {
				if(c[newstart]<=val) continue;
				int newfinish=newstart;
				while(newfinish+1<=finish && c[newfinish+1]>val) newfinish++;
				gd^=grundy(pos, newstart, newfinish);
				newstart=newfinish;
			}
			s.insert(gd);
		}

		int res=0;
		while(s.count(res)) res++;

		ret=res;
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof dp);
	int k;
	scanf("%d", &k);

	int gdvalue = 0;

	for(int i=0; i<k; i++) {
		int size;
		scanf("%d", &size);

		for(int j=0; j<size; j++) {
			int num;
			scanf("%d", &num);
			chain[i].push_back(num);
		}

		gdvalue^=grundy(i, 0, size-1);
	}

	if(!gdvalue)
	{
		cout << "S" << endl;
		return 0;
	} 
	
	cout << "G" << endl;

	
	for(int i=0; i<k; i++) {

		std::vector<int> & c = chain[i];
		int size = c.size();
		
		for(int j=0; j<size; j++) {
			int nx = gdvalue ^ grundy(i, 0, size-1);
			
			int val = c[j];
			
			for(int start=0; start<size; start++) {
				if(c[start]<=val) continue;
				int finish = start;
				while(finish+1<size && c[finish+1]>val) finish++;
				nx^=grundy(i, start, finish);
				start=finish;
			}

			if(nx==0) {
				cout << i+1 << " " << j+1 << endl;
				return 0;
			}
		}
	}



	return 0;
}