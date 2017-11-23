#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long long,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi() printf("hi!\n")
#define sf scanf
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)
#define infinity LLONG_MAX
#define sz 1010

using namespace std;
typedef long long int lint;
typedef double dbl;



lint danger[sz],arr[sz],d[sz],k,src,dest;;
vector<pll>v[10010];

lint check(lint value)
{
    if(danger[src]>value) return 0;
    priority_queue<pll> q;
    fill(d,d+sz,infinity);
    d[src]=0;
    q.push(pll(-0,src));
    while(!q.empty())
    {
        lint x=-q.top().first;
        lint y=q.top().second;
        q.pop();
        for(lint i=0; i<v[y].size(); i++)
        {
            lint a=v[y][i].second;
            lint b=x+v[y][i].first;
            if(b<d[a] && danger[a]<=value)
            {
                q.push(pll(-b,a));
                d[a]=b;
            }
        }
    }
    if(d[dest]<=k)
        return true;
    return false;
}
int main()
{
    lint t,n,m,x,y;
    lint c;
    sf1ll(t);
    while(t--)
    {
        sf2ll(n,k);
        for(lint i=0;i<=n+10;i++) v[i].clear();

        for(lint i=1; i<=n; i++) {
            sf1ll(danger[i]);
            arr[i]=danger[i];
        }
        sf3ll(m,src,dest);
        while(m--)
        {
            sf3ll(x,y,c);
            v[x].push_back(pll(c,y));
            v[y].push_back(pll(c,x));
        }
        sort(arr+1,arr+n+1);
        lint ans=infinity;
        lint l=1,r=n;
        while(l<=r) {
            lint mid=(l+r)/2;
            if(check(arr[mid])) {
                r=mid-1;
                ans=min(ans,arr[mid]);
            }
            else l=mid+1;
        }
        if(ans==infinity) ans=-1;
        printf("%lld\n",ans);
    }
    return 0;
}
