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
#define mx 1000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

int comp[mx];
void seive() {
    comp[1]=1;

    int stop=sqrt(mx);
    for(int i=3; i<=stop; i+=2) {
        if(comp[i]) continue;
        for(int j=i*i; j<mx; j+=i+i) {
            comp[j]=1;
        }
    }
}

int istprime(lint y) {
    lint x=sqrt(y);

    if(x*x!=y) return 0;

    if(comp[x]) return 0;
    if(x==2) return 1;
    if(x%2) return 1;
    else return 0;
}

int main()
{
    seive();
    int n;
    cin >> n;
    while(n--) {
        lint x;
        cin >> x;
        if(istprime(x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
