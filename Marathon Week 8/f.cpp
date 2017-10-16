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


int main()
{
    int n, k;
    sf2(n, k);

    priority_queue<int> q;
    FOR(i, k) {
    	int num;
    	scanf("%d", &num);
        while(num>4) {
            q.push(4);
            num = num-4;
        }
        if(num) {
            q.push(num);
        }
    }
    
    int two = n*2, four = n, one=0;

    while(!q.empty()) {
    	int people = q.top();
    	q.pop();
    	

    	if(people>2) {
    		if(four) {
    			four--;
    		}
    		else {
    			q.push(2);
    			q.push(people-2);
    		}
    	}

    	if(people==2) {
    		if(two) {
    			two--;
    		}
    		else if(four) {
    			four--;
    			one++;
    		}
    		else {
    			cout << "NO" << endl;
    			return 0;
    		}
    	}

    	if(people==1) {
    		if(one) {
    			one--;
    		}
    		else if(two) {
    			two--;
    		}
    		else if(four) {
    			four--;
    			two++;
    		}
    		else {
    			cout << "NO" << endl;
    			return 0;
    		}
    	}
    }

    cout << "YES" << endl;
    return 0;
}