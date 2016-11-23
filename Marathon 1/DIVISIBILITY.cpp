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
#define pii pair<int, int>
using namespace std;

using namespace std;
int n,k;
int a[10040], b[10040];
int dp[10001][100];
vector<pii> data;
int  mod(int a,int b=k){
    int res=a%b;
    if(res<0) res=b+res;
    return res;
}

int rec(int s,int pos)
{
    s=((s%k)+k)%k;

    if(pos==n)
    {

        //pf("%d\n",s);
        if(s==0) return 1;
        else return 0;
    }
    if(dp[pos][s]!=-1) return dp[pos][s];
    int ret1,ret2;
    ret1=rec((s+(a[pos])),pos+1);
    ret2=rec((s-(a[pos])),pos+1);
    //if(ret1 || ret2) return 1;
    dp[pos][s]=ret1|ret2;
    data.push_back(pii(pos, s));
    return dp[pos][s];
}
int main()
{
    int t;
    sf1(t);

    memset(dp,-1,sizeof(dp));

    while(t--)
    {
        data.clear();


        int i;
        int flag=0;
        sf2(n,k);

        for(i=0;i<n;i++)
        {
            sf1(a[i]);
        }
        flag=rec((a[0]),1);
        if(flag) pf("Divisible\n");
        else pf("Not divisible\n");

        for(int i=0; i<data.size(); i++) {
            dp[data[i].first][data[i].second]=-1;
        }
    }
    return 0;
}
