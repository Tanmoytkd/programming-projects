/*
ID: tanmoyk2
PROG: milk2
LANG: C++11
*/

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

int main() {

    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int n;
    sf1(n);

    int start[n+1], fin[n+1];
    FOR(i, n) {
        sf2(start[i], fin[i]);
    }

    sort(start, start+n);
    sort(fin, fin+n);

    int timer=start[0];

    int i=0, j=0;

    start[n]=INT_MAX;

    int lim=2*n, cows=0, c1=0, c2=0;

    while(lim--) {
        if(start[i]<=fin[j]) {
            if(cows==0) {
                c1=max(c1, start[i]-timer);
                timer=start[i];
            }
            cows++;
            i++;
        }
        else {
            cows--;
            if(cows==0) {
                c2=max(c2, fin[j]-timer);
                timer=fin[j];
            }
            j++;
        }
    }

    cout << c2 << " " << c1 << endl;
    return 0;
}
