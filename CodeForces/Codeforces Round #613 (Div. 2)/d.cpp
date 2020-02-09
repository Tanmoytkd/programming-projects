#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
map<tuple<int,int,int>, int> dp;

int rec(int bit, int start, int finish) {
    if(bit<0) return 0;
    int valueToFind = (arr[finish] & ( ~((1<<bit)-1) ) ) | (1<<bit);
    auto it = lower_bound(arr.begin()+start, arr.begin()+finish+1, valueToFind);
    if(it==(arr.begin()+start) || it==(arr.begin()+finish+1) ) {
        if(bit==0) return 0;
        else return rec(bit-1, start, finish);
    }
    int ret1 = (1<<bit);
    int addable1 = rec(bit-1, start, (it-arr.begin())-1);
    int addable2 = rec(bit-1, it-arr.begin(), finish);
    ret1 += min(addable1, addable2);
    return ret1;
}

int main() {
    cin >> n;
    arr = vector<int>(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << rec(30, 0, n-1) << endl;
}
