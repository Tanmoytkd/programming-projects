#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if(k>1) {
        cout << "Yes" << endl;
        return 0;
    }

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int z;
    cin >> z;
    for(int i=0; i<n; i++) {
        if(arr[i]==0) arr[i]=z;
    }

    int possible=0;
    for(int i=1; i<n; i++) {
        if(arr[i]<arr[i-1]) possible=1;
    }

    if(possible) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
