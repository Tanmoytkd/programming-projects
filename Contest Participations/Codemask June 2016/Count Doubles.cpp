#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		map<int, int> doub;
		int counter=0, num, arr[n];
		for(int i=0; i<n; i++) {
			cin >> num;
			arr[i]=num;
			doub[num*2]=1;
		}
		for(int i=0; i<n; i++) {
            num=arr[i];
            if(doub.find(num)!=doub.end()) counter++;
		}
		cout << counter << endl;
	}
	return 0;
}
