#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi() printf("hi!\n")
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

const int INF=1000000000;
int C,num=0;
int f[105][105][105],n,m;


int DFS(int x,int L,int R)
{
    if(L>R) return 0;
    int &ans=f[x][L][R],i;
    if(ans!=-1) return ans;
    ans=INF;
    for(i=L;i<=R;i++) ans=min(ans,i+max(DFS(x-1,L,i-1),DFS(x,i+1,R)));
    return ans;
}

void init()
{
    memset(f,-1,sizeof(f));
    int i,j,k;
    for(i=1;i<=100;i++) for(j=i;j<=100;j++) f[1][i][j]=(i+j)*(j-i+1)/2;
    for(i=2;i<=100;i++) for(j=1;j<=100;j++) for(k=j;k<=100;k++)
        DFS(i,j,k);
}

int main()
{
    init();
    for(scanf("%d",&C);C--;)
    {
        scanf("%d%d",&m,&n);
        printf("Case %d: %d\n",++num,f[m][1][n]);
    }
    return 0;
}
