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
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
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

int m, n, flag=0;
char arr[1002][1002], check[1002][1002];

int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};


void dfs(int row, int col) {
    if(row==m-1) {
        flag=1;
        return;
    }

    check[row][col]=1;
    FOR(i, 4) {
        if(flag) break;
        int nrow=row+dirx[i], ncol=col+diry[i];
        if(nrow<0 || nrow>=m || ncol<0 || ncol>=n) continue;
        if(check[nrow][ncol]) continue;
        if(arr[nrow][ncol]=='0')dfs(nrow, ncol);
    }
}

int main()
{
    int t, tst = 1;
    while(sf2(m, n)==2) {
        mem(check, 0);
        flag=0;
        FOR(i, m) {
            sf("%s", arr[i]);
        }

        for(int i=0; i<n; i++) {
            if(flag) break;
            if(!check[0][i] && arr[0][i]=='0') dfs(0, i);
        }

        if(flag) puts("YES");
        else puts("NO");

    }
    return 0;
}
