#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define MAX 1111


char grid[MAX][MAX];
int R, C, best;
pii nxt;

void dfs(int first, int second, int d)
{
	if(first<0 || first>=R || second<0 || second>=C || grid[first][second]!='.') return;
	grid[first][second] = 'v';
	dfs(first+1, second, d+1);
	dfs(first, second+1, d+1);
	dfs(first, second-1, d+1);
	dfs(first-1, second, d+1);
	grid[first][second] = '.';
	if(d > best)
	{
		best = d;
		nxt.first = first;
		nxt.second = second;
	}
}

int srch()
{
	int maxlen = 0;
	if(grid[nxt.first][nxt.second]!='.') return 0;
	while(true)
	{
		best = 0;
		dfs(nxt.first, nxt.second, 0);
		if(best <= maxlen) break;
		else maxlen = best;
	}
	return maxlen;
}

int main()
{
	int t, first, second;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &C, &R);
		for(first=0; first<R; first++)
			scanf("%s", grid[first]);
		nxt.first = nxt.second = 0;
		for(first=0; first<R; first++)
			for(second=0; second<C; second++)
				if(grid[first][second]=='.')
				{
					nxt.first = first;
					nxt.second = second;
					break;
				}
		printf("Maximum rope length is %d.\n", srch());
	}
	return 0;
}
