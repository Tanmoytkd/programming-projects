#include <bits/stdc++.h>
using namespace std;

int fx[]= {-1,0,1,0};
int fy[]= {0,-1,0,1};
int cnt[210][210],R,C;

vector<string>inp;

void clr()
{
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cnt[i][j]=INT_MAX;
}

void BFS()
{
    int x,y,xc,yc;
    map<pair<int,int>, bool> vis;
    pair<int,int> temp;
    pair<int,int> child;
    queue<pair<int,int> > q;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(inp[i][j]=='1')
            {
                cnt[i][j]=0;
                temp=make_pair(i,j);
                q.push(temp);
            }
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        x=temp.first,y=temp.second;
        for(int i=0; i<4; i++)
        {
            xc=x+fx[i],yc=y+fy[i];
            if(xc>=0 && xc<R && yc>=0 && yc<C && cnt[xc][yc]>cnt[x][y]+1)
            {
                child=make_pair(xc,yc);
                cnt[xc][yc]=cnt[x][y]+1;
                q.push(child);
            }
        }
    }
}
int main()
{
    int tst;
    string temp;
    cin>>tst;
    while(tst--)
    {
        
        inp.clear();
        cin>>R>>C;
        for(int i=0; i<R; i++)
        {
            cin>>temp;
            inp.push_back(temp);
        }
        clr();
        BFS();
        for(int i=0; i<R; i++)
        {
            cout<<cnt[i][0];
            for(int j=1; j<C; j++)
                cout<<" "<<cnt[i][j];
            cout<<endl;
        }
    }
}
