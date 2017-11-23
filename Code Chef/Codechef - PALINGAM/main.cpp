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

int calc(priority_queue<int> & q1, priority_queue<int> & q2) {
	if(q1.empty()) return 0;
	if(q1.top()>1) return 1;
	if(q2.empty()) return 1;
	return 0;
}

int main()
{
    int t, tst = 1;
    sf1(t);

    while(t--) {
    	char s1[1000], s2[1000];
    	scanf("%s%s", s1, s2);

    	int cnt1[30], cnt2[30];
    	memset(cnt1, 0, sizeof cnt1);
    	memset(cnt2, 0, sizeof cnt2);

    	for(int i=0; s1[i]; i++) {
    		int val=s1[i]-'a';
    		cnt1[val]++;
    		int val2=s2[i]-'a';
    		cnt2[val2]++;
    	}

    	priority_queue<int> q1, q2;
    	for(int i=0; i<26; i++) {
    		if(cnt1[i] && !cnt2[i]) q1.push(cnt1[i]);
    		if(!cnt1[i] && cnt2[i]) q2.push(cnt2[i]);
    	}

    	int res=calc(q1, q2);
    	if(res) puts("A");
    	else puts("B");
    }

    return 0;
}