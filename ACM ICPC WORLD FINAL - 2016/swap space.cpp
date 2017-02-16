#include<bits/stdc++.h>
#define pii pair<long long,long long>
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
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
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

bool comp(pii a, pii b) {
    lint p1=a.sc-a.fs;
    lint p2=b.sc-b.fs;

    if(p1>p2) return true;
    if(p1<p2) return false;
    if(a.fs>b.fs) return false;
    else return true;
}

vector<pii> v;


int possible(int extra) {
    int len=v.size();
    FOR(i, len) {
        lint fsize=v[i].fs;
        lint lsize=v[i].sc;

        extra-=fsize;
        if(extra<0) return 0;
        extra+=lsize;
    }
    return 1;
}

lint bs(lint start, lint fin) {
    if(start==fin) return start;
    lint mid=(start+fin)/2;
    if(possible(mid)) return bs(start, mid);
    else return bs(mid+1, fin);
}

int main()
{
    int t, tst = 1;
    int n;
    sf1(n);
    lint res=0;
    lint left=0;


    lint a, b;
    FOR(i, n) {
        sf2ll(a,b);
        v.pb(pii(a,b));
    }

    sort(v.begin(), v.end(), comp);

    FOR(i, v.size()) {
        lint fsize=v[i].fs;
        lint lsize=v[i].sc;

        lint mini=min(fsize, left);

        fsize-=mini;
        left-=mini;
//        cout << fsize << " " << left << " ";
        res+=fsize;
        left+=lsize;
//        cout << res << " " << left << endl;
    }

    res=bs(0, res);

    pf("%I64d\n", res);
    return 0;
}
