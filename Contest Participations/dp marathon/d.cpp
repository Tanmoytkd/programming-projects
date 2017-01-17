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


int b, k, len;
string s;
int flag;
lint dp[135000][20];

long long bigmod(long long a, long long power, long long m) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1, m))%m;
    long long r = bigmod(a, power/2, m);
    return (r*r)%m;
}

lint go(int pos, int bitmask, int mod) {
    if(pos==len) {
        if(mod==0) return 1;
        else return 0;
    }

    if(dp[bitmask][mod]==-1) {
        lint & ret = dp[bitmask][mod];
        ret=0;
        FOR(i, 21) {
            if(bitmask & (1<<i)) continue;
            if(flag & (1 << i)) {
                int newmod = (mod + ((i%k)*bigmod(b, pos, k))%k)%k;
                int newbitmask= bitmask | (1<<i);
                ret+=go(pos+1, newbitmask, newmod);
            }
        }
    }
    return dp[bitmask][mod];
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--) {
        mem(dp, -1);
        sf2(b, k);

        cin >> s;
        flag=0;
        len=s.length();

        FOR(i, s.length()) {
            char ch=s[i];
            int digit;
            if(isdigit(ch)) {
                digit=ch-'0';
                flag = flag | (1<<digit);
            }
            else if(isalpha(ch)) {
                digit=toupper(ch)-'A'+10;
                flag = flag | (1<<digit);
            }
        }

        lint res = go(0, 0, 0);
        pcase(tst++);
        pf("%lld\n", res);
    }
    return 0;
}
