#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int grid[1001][1001];
int level[1000][1000];
int n,m;
int bfs(int sx,int sy,int ex,int ey)
{
    int fx[]= {0,0,1,-1};
    int fy[]= {1,-1,0,0};
    queue<pi >q;
    memset(level,0,sizeof(level));
    level[sx][sy]=1;
    q.push(pi(sx,sy));
    while(!q.empty())
    {
        pi top;
        top=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int tx,ty;
            tx=top.first+fx[i];
            ty=top.second+fy[i];
            if(tx>=0&&ty>=0&&tx<n&&ty<m&&level[tx][ty]==0&&grid[tx][ty]!=-1)
            {
                level[tx][ty]=level[top.first][top.second]+1;
                q.push(pi(tx,ty));
            }
        }
    }
    return level[ex][ey];
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0)break;
        memset(grid,0,sizeof(grid));
        int rowtest;
        scanf("%d",&rowtest);
        while(rowtest--)
        {
            int row,ctest;
            scanf("%d%d",&row,&ctest);
            while(ctest--)
            {
                int collumn;
                scanf("%d",&collumn);
                grid[row][collumn]=-1;
            }
        }
        int sx,sy,ex,ey;
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        int sum;
        sum=bfs(sx,sy,ex,ey)-1;
        printf("%d\n",sum);
    }
    return 0;
}
