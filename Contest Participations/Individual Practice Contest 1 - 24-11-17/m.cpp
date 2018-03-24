#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long pos[1000007];

long long calculate(long long mpos) {
	long long position = pos[mpos];
	//cout << "mpos " << mpos << endl;
	int i=mpos, j=mpos;

	long long res=0;

	for(i=mpos; i>=0; i--) {
		if(pos[i]!=position) {
			i++;
			break;
		}
	}

	//cout << "i " << i << endl;



	if(i>0 && i<=mpos) {
		for(int cnt=1; cnt<=i; cnt++) {
			if(cnt%m==0 || cnt==i) {
				int newpos = i-cnt;
				res+=2*llabs(position-pos[newpos]);
			}
		}	
	}

	//cout << "Res " << res << endl;
	

	for(j=mpos; j<n; j++) {
		if(pos[j]!=position) {
			j--;
			break;
		}
	}

	//cout << "j " << j << endl;

	if(j<n-1 && j>=mpos) {
		for(int cnt=1; cnt<(n-j); cnt++) {
			if(cnt%m==0 || cnt==n-j-1) {
				int newpos = j+cnt;
				res+=2*llabs(position-pos[newpos]);
			}
		}
	}

	return res;
}

long long evaluate(long long num) {
	return min(n-1, max(num, 0LL));
}

int main() {
	
	scanf("%I64d %I64d", &n, &m);

	for(long long i=0; i<n; i++) {
		scanf("%I64d", &pos[i]);
	}

	vector<long long> midpos;

	for(int x=-10; x<=10; x++) {
		midpos.push_back(evaluate(n/2+x));
	}


	long long res= LLONG_MAX;

	 for(long long i=0; i<midpos.size(); i++) {
	 	long long mpos = midpos[i];
		// cout << "MPOS " << mpos  << endl;
		// cout << "tada " <<  calculate(mpos) << endl;;
	 	res=min(res, calculate(mpos));
	 }


	// for(int i=0; i<n; i++) {
	// 	cout << calculate(i) << endl;
	// 	res = min(res, calculate(i));
	// }

	printf("%I64d\n", res);
}