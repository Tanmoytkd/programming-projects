#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,pair<int, int> >
int fx[12] = {0, 0, 1, -1, 0, 0, 2, -2, 1, 1, -1, -1};
int fy[12] = {1, -1, 0, 0, 2, -2, 0, 0, 1, -1, 1, -1};

int n, m, k, add;
map<int, int> mark[10001], lvl[10001], visited[10001];
vector<int> mr[10001], mc[10001];

void dijkstra() {
    priority_queue< pii , vector<pii >, std::greater<pii> > q;
    q.push({0, {1, 1}});

    while(!q.empty()) {
        auto x = q.top();
        int cost = x.first;
        int r = x.second.first;
        int c = x.second.second;

        q.pop();
        if(visited[r][c]) continue;
        visited[r][c]=1;

        cout << "Current Node: " << r << " " << c << " distance: " << lvl[r][c] << endl;

        for(int i=0; i<4; i++) {
            int row = r+fx[i];
            int col = c+fy[i];

            if(row<1 || row>n || col<1 || col>m) continue;
            if(visited[row][col]) continue;
            if(!mark[row][col]) continue;
            int newcost = cost + (i>=4);
            if(lvl[row].count(col)==0) {
                lvl[row][col]=newcost;
                q.push({newcost, {row, col}});
            }
            else if(lvl[row][col]>newcost) {
                lvl[row][col]=newcost;
                q.push({newcost, {row, col}});
            }
        }

        for(int dist=-2; dist<=2; dist++) {
            int newrow, newcol;
            newrow=min(max(r+dist, 1), n);
            vector<int> & v = mr[newrow];
            for(int i=0; i<v.size(); i++) {
                newcol = v[i];

                if(add && abs(dist)==2 && newrow==n && newcol==m) continue;
                if(newrow<1 || newrow>n || newcol<1 || newcol>m) continue;
                if(visited[newrow][newcol]) continue;
                if(!mark[newrow][newcol]) continue;
                int newcost = cost + 1;
                if(lvl[newrow].count(newcol)==0) {
                    lvl[newrow][newcol]=newcost;
                    q.push({newcost, {newrow, newcol}});
                }
                else if(lvl[newrow][newcol]>newcost) {
                    lvl[newrow][newcol]=newcost;
                    q.push({newcost, {newrow, newcol}});
                }
            }

            newcol=min(max(c+dist, 1), m);
            vector<int> & vv = mc[newcol];
            for(int i=0; i<vv.size(); i++) {
                newrow = vv[i];

                if(add && abs(dist)==2 && newrow==n && newcol==m) continue;
                if(newrow<1 || newrow>n || newcol<1 || newcol>m) continue;
                if(visited[newrow][newcol]) continue;
                if(!mark[newrow][newcol]) continue;
                int newcost = cost + 1;
                if(lvl[newrow].count(newcol)==0) {
                    lvl[newrow][newcol]=newcost;
                    q.push({newcost, {newrow, newcol}});
                }
                else if(lvl[newrow][newcol]>newcost) {
                    lvl[newrow][newcol]=newcost;
                    q.push({newcost, {newrow, newcol}});
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int r, c;
    for(int i=1; i<=k; i++) {
        scanf("%d%d", &r, &c);
        mark[r][c]=1;
        mr[r].push_back(c);
        mc[c].push_back(r);
    }
    add=0;
    if(mark[n][m]==0) {
        mark[n][m]=1;
        mr[n].push_back(m);
        mc[m].push_back(n);
        add=1;
    }
    dijkstra();
    if(lvl[n].count(m)==0) cout << -1 << endl;
    else cout << lvl[n][m]+add << endl;

    return 0;
}
