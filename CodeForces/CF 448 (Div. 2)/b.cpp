#include <bits/stdc++.h>
using namespace std;

int n, x, k;
int arr[100007];
getdivs(int a, int b) {
	if(a>b) swap(a, b);
	return ((b/x) - (a-1)/x);
}

int main() {
	scanf("%d%d%d", &n, &x, &k);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	vector<pair<int, int> > v;
	for(int i=0; i<n; i++) {
		v.push_back({arr[i], i});
	}

	sort(v.begin(), v.end());


}