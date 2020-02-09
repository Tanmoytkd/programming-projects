#include <bits/stdc++.h>
using namespace std;
#define mxn 300007

int arr[mxn][10], n, m, val[mxn][10];
map<int, vector< pair<int,int> > > pos;
set<int> cnt[1024];
bool doneOnce = false;
map<int, vector< pair<int, int> > >::iterator midit;

int mask(int row) {
    int res = 0;
    for(int col=1; col<=m; col++) {
        res = res*2 + val[row][col];
    }
    return res;
}

void preprocess(int mid) {
    if(doneOnce) {
        auto midpos = pos.lower_bound(mid);

        while(midpos->first<midit->first) {
            for(auto ijpair: midpos->second) {
                int row = ijpair.first, col = ijpair.second;
                cnt[mask(row)].erase(row);
                val[row][col] = 1;
                cnt[mask(row)].insert(row);
            }
            midpos++;
        }
        while(midpos->first>midit->first) {
            for(auto ijpair: midit->second) {
                int row = ijpair.first, col = ijpair.second;
                cnt[mask(row)].erase(row);
                val[row][col] = 0;
                cnt[mask(row)].insert(row);
            }
            midit++;
        }
        midit = pos.lower_bound(mid);
    } else {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(arr[i][j]<mid) val[i][j] = 0;
                else val[i][j] = 1;
            }
            cnt[mask(i)].insert(i);
        }
        midit = pos.lower_bound(mid);
        doneOnce = true;
    }
}

pair<int,int> check(int mid) {
    preprocess(mid);
    vector<int> masks;
    for(int msk=0; msk<1024; msk++) {
        if(!cnt[msk].empty()) masks.push_back(msk);
    }

    set<int> mxmsk = cnt[(1<<m)-1];
    if(!mxmsk.empty()) return { *mxmsk.begin(), *mxmsk.begin() };

    for(int msk1: masks) {
        for(int msk2: masks) {
            if( (msk1|msk2)==((1<<m)-1) ) return { *cnt[msk1].begin(), *cnt[msk2].begin() };
        }
    }
    return {-1,-1};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    long long low = INT_MAX, high = INT_MIN;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> arr[i][j];
            low = (low<arr[i][j]) ? low:arr[i][j];
            high = (high>arr[i][j]) ? high:arr[i][j];
            pos[ arr[i][j] ].push_back({i,j});
        }
    }


    pair<int,int> not_found(-1,-1);

    pair<int,int> bestmasks;

    while(low<=high) {
        int mid = (low+high)/2;

        pair<int, int> masks = check(mid);
        if(masks==not_found) {
            high = mid-1;
        }
        else {
            bestmasks = masks;
            low = mid+1;
        }
    }

    cout << bestmasks.first << " " << bestmasks.second << endl;

    return 0;
}
