#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, y, j;
    cin >> n >> m;

    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin>>arr[i][j];
        }
    }

    int totalmasks = 1<<m;

    vector<pair<int,int>> B(totalmasks);


    for(int mask=0; mask<(totalmasks); mask++) {
        for(int i=0; i<n; ++i) {
            for(j=0,y=1e9; j<m; ++j)
                if((mask>>j)%2==1)
                    y=min(y,arr[i][j]);
            B[mask]=max(B[mask], {y,1+i});
        }
    }

    pair<int,int>x= {0,0};
    for(int i=0; i<totalmasks; ++i)
        x=max(x, {min(B[i].first,B[(1<<m)-i-1].first),i});
    cout<<B[x.second].second<<' '<<B[(1<<m)-x.second-1].second;
}
