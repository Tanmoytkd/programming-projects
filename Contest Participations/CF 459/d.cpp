#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

vector<pii> edge[107];
int n, m;

int dp[107][107][27][2];

int rec(int a, int b, int mini, int whosemove=1) {
    int &ret = dp[a][b][mini][whosemove];
    if(ret==-1) {
        set<int> st;
        int starter;
        if(whosemove) starter = a;
        else starter = b;
        vector<pii>& e = edge[starter];

        pii srch = make_pair(mini, 0);
        int strtpos = lower_bound(e.begin(), e.end(), srch)-e.begin();
        //cout << starter << " " << strtpos << endl;;

        for(int i=strtpos; i<e.size(); i++) {
            pii moves = e[i];
            if(whosemove) st.insert(rec(moves.second, b, moves.first, !whosemove));
            else st.insert(rec(a, moves.second,moves.first, !whosemove ));
        }


        ret=0;
        while(st.count(ret)) ret++;
    }
    return ret;
}

int main(){
    scanf("%d%d", &n, &m);

    memset(dp, -1, sizeof dp);

    for(int i=0; i<m; i++) {
        int v, u;
        char c;
        scanf(" %d %d %c", &v, &u, &c);

        edge[v].push_back(make_pair(c-'a', u));
        //cout << c-'a' << endl;
    }

    for(int i=1; i<=n; i++) {
        sort(edge[i].begin(), edge[i].end());
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(rec(i, j, 0, 1)) printf("A");
            else printf("B");
        }
        puts("");
    }
        return 0;
}
