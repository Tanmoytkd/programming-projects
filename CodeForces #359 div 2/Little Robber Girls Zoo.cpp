#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int n;
	cin >> n;
	long long arr[n+10];
	int pos=0;
	for(int i=pos;i<n; i=++pos) {
		cin >> arr[i];
		if(i==0) continue;
		while(arr[i]<arr[i-1]) {
            long long temp=arr[i-1];
			arr[i-1] = arr[i];
            arr[i] = temp;

			cout << i << " " << i+1 << endl;
			i--;
			if(i==0) break;
		}
	}

	return 0;
}
