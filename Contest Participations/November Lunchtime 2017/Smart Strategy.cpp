#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);


	while(t--) {
		long long n, q;
		scanf("%lld %lld", &n, &q);



		long long arr[n];
		vector<long long> vals;
		
		for(int i=0; i<n; i++) {
			scanf("%lld", &arr[i]);

			if(arr[i]!=1) {
				vals.push_back(arr[i]);
			}			
		}

		int valid=1;
		if(vals.size()>=33) valid=0;

		for(int i=0; i<q; i++) {
			long long num;
			scanf("%lld", &num);

			if(i!=0) printf(" ");
			if(!valid) printf("0");
			else {
				for(int j=0; j<vals.size(); j++) num/=vals[j];
				printf("%lld", num);
			}
		}
		puts("");
	}

}