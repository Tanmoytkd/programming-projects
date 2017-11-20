#include<bits/stdc++.h>
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

int n;
int visit[10][10], arr[10][10];
int fx[4]= {0, 0, 1, -1}, fy[4]={1, -1, 0, 0};

int go(int row, int col) {
	memset(visit, 0, sizeof visit);
	int res=INT_MIN, sum=0;
	
	priority_queue< pair< int, pair<int, int> > > pq;
	pq.push(make_pair(res, make_pair(row, col)));
	visit[row][col]=1;

	while(!pq.empty()) {
		pair<int, pair<int, int> > top = pq.top();
		int r=top.sc.fs;
		int c=top.sc.sc;
		sum+=top.fs;
		res=max(res, sum);
		visit[r][c]=1;
		pq.pop();

		for(int i=0; i<4; i++) {
			int nr=r+fx[i], nc=c+fy[i];
			if(nr<1 || nr>n || nc<1 || nc>n) continue;
			if(visit[nr][nc]) continue;
			pq.push(make_pair(arr[nr][nc], make_pair(nr, nc)));

		}
	}
	return res;
}

int main()
{
    
    sf1(n);

    return 0;
}