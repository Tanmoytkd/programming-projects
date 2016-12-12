#include<bits/stdc++.h>
#define pii pair<lint,lint>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf printf
#define pf1(a) printf("%lld\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%lld",&a)
#define sf2(a,b) scanf("%lld %lld",&a,&b)
#define sf3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %lld: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(lint i=0;i<(x); i++)
#define FOR1(i, x) for(lint i = 1; i<=x ; i++)

using namespace std;
typedef long long lint;
typedef double dbl;

struct order {
    lint strt, fin, cost, passenger, profit;
    order(lint x, lint y, lint z) {
        strt=x;
        fin=y;
        cost=abs(x-y);
        passenger=z;
        profit=cost*passenger;
    }
};

bool func(order a, order b) {
    return a.strt<b.strt;
}

lint n, m, x;
vector<order> orders, curr;
lint maxprofit;
lint totalprofit=0;

lint valid() {
    lint res=1;
    FOR(i, 7) {
        lint total=0;
        FOR(j, curr.size()) {
            if(curr[j].strt<=i && curr[j].fin>i)
            total+= curr[j].passenger;
        }
        res = res && (total<=n);
    }
    return res;
}

//lint totalprofit() {
//    lint total=0;
//    FOR(i, curr.size()) {
//        total+=curr[i].profit;
//    }
//    return total;
//}

void go(lint pos) {
    if(pos>0) {
        if(valid()) {
//            cout << "current " << pos << endl;
//            FOR(i, curr.size()) {
//                cout << curr[i].strt << " " << curr[i].fin << " " << curr[i].passenger << endl;
//            }
//            cout << endl;
            maxprofit = max(maxprofit, totalprofit);
        }
        else return;
    }

    if(pos>=x) return;

    for(lint i=pos; i<x; i++) {
        curr.pb(orders[i]);
        totalprofit+=orders[i].profit;
        go(i+1);
        curr.ppb();
        totalprofit-=orders[i].profit;
    }
}

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // TKD
    while(sf3(n, m, x)==3) {
        if(!n && !m && !x) break;
        //cout << n << endl << m << endl<< x << endl;
        curr.clear();
        vector<order> arr;
        lint t=x;
        while(t--) {
            lint a, b, c;
            sf3(a,b,c);
            arr.pb(order(a,b,c));
        }
        orders=arr;
        sort(orders.begin(), orders.end(), func);

//        FOR(i, orders.size()) {
//            cout << orders[i].strt << " " << orders[i].fin << " " << orders[i].passenger << endl;
//        }

        maxprofit=0;
        go(0);

        if(maxprofit<0) maxprofit=0;
        pf1(maxprofit);
    }
    return 0;
}

/*
10 3 4
0 2 1
1 3 5
1 2 7
2 3 10
10 5 4
3 5 10
2 4 9
0 2 5
2 5 8
0 0 0
*/
