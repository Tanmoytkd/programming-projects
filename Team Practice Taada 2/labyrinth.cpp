#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int fx[4] = {-1, 1, 0, 0};
int fy[4] = {0, 0, -1, 1};

char a[1007][1007];
int level[1007][1007], visit[1007][1007];


int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--) {
    	int col, row;
    	sf2(col, row);

    	//pf("%d %d\n", col, row);

    	
    	FOR(i, row) {
    		sf("%s", a[i]);
    		//pf("%s\n", a[i]);
    	}

    	pii start(-1, -1), end1, end2;
    	FOR(i, row) {
    		if(start!=pii(-1, -1)) break;
    		FOR(j, col) {
    			if(a[i][j]=='.') {
    				start = pii(i, j);
    				break;
    			}
    		}
    	}

    	//cout << start.fs << " " << start.sc << endl;

    	memset(level, -1, sizeof level);
    	memset(visit,  0, sizeof visit);

    	queue< pii > q;
    	q.push(start);

    	while(!q.empty() ) {
    		end1=q.front();
    		int r = end1.first, c = end1.second;
    		visit[r][c]=1;
    		q.pop();

    		FOR(i, 4) {
    			int nr = r+fx[i], nc = c+fy[i];
    			if(nr<0 || nr>=row || nc<0 || nc>=col) continue;
    			if(visit[nr][nc]) continue;
    			if(a[nr][nc]!='.') continue;
    			q.push(pii(nr, nc));
    		}
    	}

    	

    	q = queue< pii >();
    	q.push(end1);
    	level[end1.fs][end1.sc]=0;

    	int res = 0;

    	while(!q.empty()) {
    		end2 = q.front();
    		int r = end2.fs, c = end2.sc;
    		//cout << "found " << r << " " << c << endl;
    		int l = level[r][c];
    		q.pop();

    		FOR(i, 4) {
    			int nr = r+fx[i], nc = c+fy[i];
    			if(nr<0 || nr>=row || nc<0 || nc>=col) continue;
    			if(level[nr][nc]!=-1) continue;
    			if(a[nr][nc]!='.') continue;
    			level[nr][nc]=l+1;
    			q.push(pii(nr, nc));
    			if(level[nr][nc]>res) res = level[nr][nc];
    		}
    	}

    	//cout << end1.fs << " " << end1.sc << endl;
    	//cout << end2.fs << " " << end2.sc << endl;

    	pf("Maximum rope length is %d.\n", res);

    }
    return 0;
}