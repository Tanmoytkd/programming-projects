#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
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

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
    	int flag[n+2];
    	int mat[n+2][n+2];
    	int cnt=0;
    	int ans[n+2][n+2];
    	mem(flag,0);
    	mem(ans,-1);
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++) scanf("%1d",&mat[i][j]);
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++) if(mat[i][j]==0) mat[i][j]=105;
    	for(int k=0;k<n;k++)
    		for(int i=0;i<n;i++)
    			for(int j=0;j<n;j++)
    			{
    				if(i==j) continue;
    				if(mat[i][k]+mat[k][j]<mat[i][j])
    				{
    					ans[i][j]=k;
    					mat[i][j]=mat[i][k]+mat[k][j];
    				}
    			}
    	for(int k=0;k<n;k++)
    		for(int i=0;i<n;i++)
    			for(int j=0;j<n;j++)
    			{
    				if(i==j) continue;
    				if(mat[i][k]+mat[k][j]==mat[i][j])
    				{
    					if(k!=ans[i][j]) ans[i][j]=-1;
    					// cout<<i<<" "<<j<<" "<<k<<endl;
    					// ans[i][j]=k;
    					// mat[i][j]=mat[i][k]+mat[k][j];
    				}
    			}
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			if(ans[i][j]!=-1)
    				if(flag[ans[i][j]]==0)
    					flag[ans[i][j]]=1,cnt++;
 
 
    	printf("%d\n",cnt);
    }
    return 0;
}
/*sample
    
*/