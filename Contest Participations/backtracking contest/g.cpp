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

lint possible=0, depth=0, maxdepth=0;

int go(lint sum) {
    char ch;
    lint num=0, internal=0, neg=0;
    while(sf(" %c", &ch)) {
        if(ch=='-') {
            neg=1;
        }
        else if(isdigit(ch)) {
            num*=10;
            num+=ch-'0';
        }
        else if(ch=='(') {
            internal++;
            if(neg) internal+= go(sum+num);
            else internal += go(sum-num);
        }
        else if(ch==')') {
            if(neg) num=0-num;
            if(internal==2 && sum==num) {
                    possible=1;
            }
            return internal;
        }
    }
}

int main()
{
    lint t, tst = 1, sum;
    while(sf1(sum)==1) {
        char ch;
        sf(" %c", &ch);
        depth=1;
        possible=0;
        go(sum);
        if(possible) puts("yes");
        else puts("no");
    }

    return 0;
}
