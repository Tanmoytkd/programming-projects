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


int main()
{
    int n;
    sf1(n);

    int x=0, y=0, valid=1;
    while(n--) {
        int dist;
        string dir;

        cin >> dist >> dir;

        if(y<0 || y>20000) valid=0;
        if(y==0) {
            if(dir=="South") {
                y+=dist;
            }
            else valid=0;
        }
        else if(y==20000) {
            if(dir=="North") {
                y-=dist;
            }
            else valid=0;
        }
        else {
            if(dir=="South") {
                y+=dist;
            }
            else if(dir=="North") {
                y-=dist;
            }
        }
    }

    if(valid && y==0) {
        puts("YES");
    }
    else {
        puts("NO");
    }
    return 0;
}
