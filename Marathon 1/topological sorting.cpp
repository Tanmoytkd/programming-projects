/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;

const int N=1005;
const int M=100005;
int power(int a,int b,int c)
{
    int ans=1;
    while(b)
    {
        if(b%2==1)
        {
            ans=(ans*a)%c;
            b--;
        }
        b/=2;
        a=a*a%c;
    }
    return ans;
}
int in[N],vis[N],w[N][N];
int n,m,k;
vector<int>vec[N];

int main()
{
    int a,b;
    int flag=1;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        if(!w[a][b])
        {
            w[a][b]=1;
            vec[a].pb(b);
        }
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&in[i]);
    }
    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        for(int j=i+1; j<=n; j++)
        {
            if(w[in[i]][in[j]])cnt++;
        }
        if(cnt!=vec[in[i]].size())flag=0;

    }
    if(flag)printf("YES\n");
    else printf("NO\n");
    return 0;
}
