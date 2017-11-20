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

struct ball {
	int a[3];
	ball(int x, int y, int z) {
		a[0]=x;
		a[1]=y;
		a[2]=z;
		sort(a, a+3);
	}
	void print() {
		printf("%d %d %d\n", a[2], a[1], a[0]);
	}

};

int main()
{
    int n;
    sf1(n);

    map<int, int> cnt;
    for(int i=0; i<n; i++) {
    	int num;
    	sf1(num);
    	cnt[num]++;
    }

    priority_queue<pair<int, int> > pq;

    map<int, int> :: iterator it;
    for(it=cnt.begin(); it!=cnt.end(); it++) {
    	pq.push(make_pair(it->second, it->first));
    }

    vector<ball> vb;
    while(pq.size()>=3) {
    	pair<int, int> p1, p2, p3;
    	p1=pq.top();
    	pq.pop();
    	p2=pq.top();
    	pq.pop();
    	p3=pq.top();
    	pq.pop();

    	vb.push_back(ball(p1.second, p2.second, p3.second));
    	if(p1.first>1) pq.push(make_pair(p1.first-1, p1.second));
    	if(p2.first>1) pq.push(make_pair(p2.first-1, p2.second));
    	if(p3.first>1) pq.push(make_pair(p3.first-1, p3.second));
    }

    pf1(vb.size());
    for(int i=0; i<vb.size(); i++) {
    	vb[i].print();
    }
    return 0;
}