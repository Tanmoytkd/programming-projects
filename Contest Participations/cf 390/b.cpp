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

char board[5][5];
int possible=0;

int fx[4]={1, 0, 1, 1};
int fy[4]={0, 1, 1, -1};

int valid(char ch) {
    return ch=='.' || ch=='x';
}
void go(int i, int j, int dir) {
    int total=0, dot=0;
    FOR(pos, 3) {
        int nextrow=i+pos*fx[dir], nextcol=j+pos*fy[dir];
        if(nextrow<0 || nextrow>=4 || nextcol<0 || nextcol>=4) return;
        char next=board[nextrow][nextcol];
        total+=valid(next);
        dot+=(next=='.');
    }
    if(total==3 && dot<=1) possible=1;
}

int main()
{
    FOR(i, 4) {
        sf("%s", board[i]);
    }

    FOR(i, 4) {
        FOR(j, 4) {
            if(valid(board[i][j])) {
                FOR(k, 4) {
                    go(i, j, k);
                }
            }
            if(possible) break;
        }
        if(possible) break;
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
