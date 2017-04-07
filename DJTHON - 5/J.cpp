#include <bits/stdc++.h>
using namespace std;
#define mx 1000007

int cnt[mx], cnt2[mx], cum[mx], rev[mx], arr[mx], n;
map<int, int> mp;
vector<int> tree[4*mx];

void build(int node, int start, int fin) {
    if(start==fin) {
        tree[node].push_back(rev[start]);
        return;
    }

    int mid = (start+fin)/2;
    int left = node*2;
    int right = left+1;
    build(left, start, mid);
    build(right, mid+1, fin);

    std::merge(tree[left].begin(), tree[left].end(), tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
}

long long int query(int node, int start, int fin, int i, int j, int x) {
    if(start>j || fin<i) return 0;
    if(start>=i && fin <=j) return lower_bound(tree[node].begin(), tree[node].end(), x)-tree[node].begin();

    int mid = (start+fin)/2;
    int left = node*2;
    int right = left+1;

    return query(left, start, mid, i, j, x) + query(right, mid+1, fin, i, j, x);
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    int index=1;
    for(int i=1; i<=n; i++) {
        if(mp.count(arr[i])==0) {
            mp[arr[i]]=index++;
        }
        arr[i]=mp[arr[i]];
    }

    for(int i=1; i<=n; i++) {
        cnt[arr[i]]++;
        cum[i]= cnt[arr[i]];
    }
    for(int i=n; i>0; i--) {
        cnt2[arr[i]]++;
        rev[i]= cnt2[arr[i]];
    }

    build(1, 1, n);
    long long int sum=0;
    for(int i=1; i<n; i++) {
        sum += query(1, 1, n, i+1, n, cum[i]);
    }

    cout << sum << endl;
    return 0;
}
