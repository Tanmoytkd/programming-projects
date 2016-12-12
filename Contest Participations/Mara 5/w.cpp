#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;
#define pi pair<int,int>

int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};

int grid[500][500],visited[500][500],ans[500][500];
char ch[500][500];
int m,n,q,h,t;

void bfs(int x,int y){
    visited[x][y]=1;
    ans[x][y]=0;

    queue<pi> p, q;
    q.push(pi(x,y));
    p.push(pi(x,y));

    while(!q.empty()){
        pi top=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int tx=top.first+fx[i];
            int ty=top.second+fy[i];

            if(tx>=0 && tx<m && ty>=0 && ty<n && (grid[tx][ty]==0|| grid[tx][ty]==-1) && visited[tx][ty]==0)
			{
				visited[tx][ty]=1;
				q.push(pi(tx,ty));
				p.push(pi(tx,ty));
                if(grid[tx][ty]==-1) ans[x][y]++;
			}

        }
    }

    while(!p.empty()) {
        pi top=p.front();
        ans[top.first][top.second]=ans[x][y];
        p.pop();
    }

}

int main(){
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(grid,0,sizeof(grid));
        memset(ans,-1,sizeof(ans));
        scanf("%d %d %d",&m,&n,&q);

        getchar();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%c",&ch[i][j]);
                if(ch[i][j]=='#') grid[i][j]=1;
                else if(ch[i][j]=='C') grid[i][j]=-1;
            }
            getchar();
        }
        int x,y,ans1;

        printf("Case %d:\n",h);
        for(int i=0;i<q;i++){
            memset(visited,0,sizeof(visited));
            scanf("%d %d",&x,&y);
            if(ans[x-1][y-1]==-1) bfs(x-1,y-1);
            printf("%d\n",ans[x-1][y-1]);
        }


    }
}
