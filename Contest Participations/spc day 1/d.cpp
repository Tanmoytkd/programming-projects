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

int C,num=0;
int n,a[105];
i64 f[50005];



int main()
{
    for(scanf("%d",&C);C--;)
    {
        scanf("%d",&n);
        int i,j,sum=0,t;
        for(i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
        t=sum>>1;
        memset(f,0,sizeof(f));
        f[0]=1;
        for(i=1;i<=n;i++) for(j=t;j>=a[i];j--) f[j]|=f[j-a[i]]<<1;
        int x=(n+1)>>1,y=n>>1;
        i64 p=1;
        for(j=t;j>0;j--)
        {
            if((f[j]&(p<<x))||(f[j]&(p<<y))) break;
        }
        printf("Case %d: %d %d\n",++num,j,sum-j);
    }
    return 0;
}