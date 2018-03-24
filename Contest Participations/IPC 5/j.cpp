#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001
int arr[MAXN];
int main()
{

	int n;
	scanf("%d", &n);
	
	int mxval = 0;
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
		mxval = max(mxval, arr[i]);
	}

	sort(arr, arr+n);

	long long mx = 0;
	for(int i=0; i<n; i++) {
		if(i!=0 && arr[i]==arr[i-1]) continue;
		int lead = arr[i];
		//cout << lead << endl;
		

		int prev = 0;
		long long sum = 0;
		int srch = 0;
		for(int j=1; ; j++) {
			srch += lead;
			
			int pos = lower_bound(arr+i, arr+n, srch)-arr;
			if(pos==prev) continue;
			long long add = (long long) (pos-prev)*(srch-lead);
			sum+=add;
			prev=pos;
			if(srch>mxval) break;
			//if(add!=0) cout << add << " ";
		}

		//cout << endl;
		
		mx=max(mx, sum);
	}

	cout << mx << endl;
	

	return 0;
}