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
    string x;
    cin >> x;

    string res=x;
    int mx=0;
    for(int i=0; i<x.size(); i++) {
    	mx+=x[i]-'0';
    }

    if(x.size() == 1) {
    	cout << x << endl;
    	return 0;
    }

    if(x[0]!='1') {
    	string temp=x;
    	temp[0]--;
    	int sum=temp[0]-'0';
    	
    	for(int i=1; i<temp.size(); i++) {
    		temp[i]='9';
    		sum+=9;
    	}

    	if(sum>mx && temp<x) {
    		cout << temp << endl;
    		return 0;
    	}
    }
    for(int i=1; i<x.size()-1; i++) {
    	string temp=x;
    	int sum=0;
    	if(temp[i]=='0') continue;
    	for(int j=0; j<i; j++) sum+=temp[j]-'0';
    	temp[i]--;
    	sum+=temp[i]-'0';
    	for(int j=i+1; j<x.size(); j++) {
    		temp[j]='9';
    		sum+=9;
    	}

    	if(sum>mx && temp<=x) {
    		mx=sum;
    		res=x;
    	}
    }

    cout << res << endl;
    return 0;
}