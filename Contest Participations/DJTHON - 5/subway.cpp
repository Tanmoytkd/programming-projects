/*input
6
1 2
3 4
6 4
2 3
1 3
3 5
*/
#include <bits/stdc++.h>
using namespace std;

int n,a,b,i,visit[3005],dist[3005];
vector<int> edge[3005];

void dfs(int x,int y){
	visit[x]++;
	int j=0;
	while(j<edge[x].size()){
		vector<int> & e = edge[x];
		if(visit[e[j]]==0)
			dfs(e[j],x);
		else if(e[j]!=y && x!=a)
			dist[x]=0,a=e[j];
		j++;
	}
	if(x!=a && dist[x]==0)
		dist[y]=0;
}

void dfs_dist(int x){
	visit[x]++;
	int j=0;
	vector<int> & e = edge[x];
	while(j<e.size()){
		if(visit[e[j]]==0){
			if(dist[e[j]]==-1)
				dist[e[j]]=dist[x]+1;dfs_dist(e[j]);
		}
		j++;
	}
}

int main(){
	cin>>n;

	while(i<n){
		cin>>a>>b;
		dist[i+1]=-1;
		edge[a].push_back(b);
		edge[b].push_back(a);
		i++;
	}

	i=0;a=-1;
	dfs(1,0);
	memset(visit,0,sizeof(visit));
	dfs_dist(a);

	while(i<n){
		cout<<dist[i+1]<<" ";
		i++;
	}
	return 0;
}
