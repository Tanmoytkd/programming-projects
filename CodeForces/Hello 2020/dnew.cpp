#include <bits/stdc++.h>

const int N=100005;
int n,r[N],a[2][N],b[2][N],Val[2][N],u[N];
std::mt19937 Rand(time(0));

void Calc(int k)
{
    std::priority_queue<std::pair<int,int> > q;
    for(int i=1;i<=n;++i)q.push(std::make_pair(a[k][i],-i)),q.push(std::make_pair(b[k][i],i));
    for(int hx=0,px=0;!q.empty();)
    {
        int t=q.top().second;
        q.pop();
        if(t<0)hx^=r[-t],Val[k][-t]^=px^u[-t];
        else if(t>0)u[t]=px,Val[k][t]^=hx,hx^=r[t],px^=r[t];
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d%d%d",&a[0][i],&b[0][i],&a[1][i],&b[1][i]),r[i]=Rand();
    Calc(0),Calc(1);
    for(int i=1;i<=n;++i)if(Val[0][i]!=Val[1][i])return puts("NO"),0;
    return puts("YES"),0;
}
