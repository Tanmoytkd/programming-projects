#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

int n;
int t[31];
int dirx[8]={0, 1, 1, 1, 0, -1, -1, -1};
int diry[8]={1, 1, 0, -1, -1, -1, 0, 1};

int board[400][400];
int dp[400][400][31][10];
//set<pii> coord;

void go(int x, int y, int level, int dir) {
    if(dp[x][y][level][dir]) return;
    if(level==n) return;

    dp[x][y][level][dir]=1;

    board[x][y]=1;
    //coord.insert(pii(x,y));
    FOR(i, t[level]-1) {
        x+=dirx[dir];
        y+=diry[dir];

        //coord.insert(pii(x, y));
        board[x][y]=1;
    }

    int dir1=(dir+1)%8;
    int dir2=(dir-1+8)%8;

    go(x+dirx[dir1], y+diry[dir1], level+1, dir1);
    go(x+dirx[dir2], y+diry[dir2], level+1, dir2);


}

int main()
{
    sf1(n);
    FOR(i, n) sf1(t[i]);

    go(200, 200, 0, 0);

    int total=0;

    FOR(i, 400) {
        FOR(j, 400) {
            total+=board[i][j];
        }
    }

    cout << total << endl;

    //cout << coord.size() << endl;
    return 0;
}
