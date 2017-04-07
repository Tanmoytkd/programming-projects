/*
ID: tanmoyk2
PROG: skidesign
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n;

int go(int arr[], int low, int high) {
	int res=0;
	for(int i=0; i<n; i++) {
		int diff=0;
		if(arr[i]<low) diff=low-arr[i];
		if(arr[i]>high) diff=arr[i]-high;
		res+=diff*diff;
	}
	return res;
}

int main() {
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
    fin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        fin >> arr[i];
    }

    sort(arr, arr+n);

    int res=INT_MAX;
    int low=0, high=low+17;
    while(high<=100) {
        res= min(res, go(arr, low, high));
        low++;
        high++;
    }

    fout << res << endl;

    return 0;
}
