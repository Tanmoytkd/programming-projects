#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
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

struct order {
    int strt, fin, cost, passenger;
    order(int x, int y, int z) {
        strt=x;
        fin=y;
        cost=abs(x-y);
        passenger=z;
    }
};
int n, m, x;
vector<order> orders, curr;
int ipos=0;
int dp[30][1000];

bool func(order a, order b) {
    return a.strt<b.strt;
}

int go(int pos, int rest) {
    if(pos>=x) return 0;

    order ix=orders[pos];

    int strt=ix.strt;
    while(ipos<curr.size() && curr[ipos].fin<=strt) {
        rest+=curr[pos].passenger;
        ipos++;
    }

    if(rest<0) return INT_MIN;


    if(dp[pos][rest]==-1) {
        int one=go(pos+1, n);

        int two=0;
        if(ix.passenger < rest) {
            curr.pb(ix);
            two=ix.cost*ix.passenger + go(pos+1, rest-ix.passenger);
        }
        if(one<0 && two<0) dp[pos][rest]=0;
        else if(one<0 && two>=0) dp[pos][rest]=two;
        else if(two<0) dp[pos][rest]=one;
        else dp[pos][rest]=max(one, two);
    }
    return  dp[pos][rest];
}

int main()
{
    int t, tst = 1;
    while(sf3(n, m, x)==3 && n && m && x) {
        memset(dp, -1, sizeof dp);
        vector<order> arr;
        t=x;
        while(t--) {
            int a, b, c;
            sf3(a,b,c);
            arr.pb(order(a,b,c));
        }
        orders=arr;
        sort(orders.begin(), orders.end(), func);

//        FOR(i, orders.size()) {
//            order x=orders[i];
//            cout << x.cost << " " << x.passenger << endl;
//        }
        ipos=0;
        int res=go(0, n);
        pf1(res);
    }
    return 0;
}
