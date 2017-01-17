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

    int total=n, one=0, two=0, twodiffmax=INT_MIN, diff=0;
    int diffs[n+1], divs[n+1], pos=0, finaldiff=0;

    while(n--) {
        int c, d;
        sf2(c, d);

        diffs[pos]=diff;
        divs[pos]=d;
        pos++;

        if(d==2) {
            two++;
            twodiffmax= max(twodiffmax, diff);
        }
        if(d==1) {
            one++;
        }


        diff+=c;
        finaldiff=diff;
    }

    if(one==total) {
        cout << "Infinity" << endl;
    }
    else {
        int possible=1;
        int start=1899-twodiffmax;

        FOR(i, total) {
            if(divs[i]==1 && start+diffs[i]<=1899) possible=0;
            else if(divs[i]==2 && start+diffs[i]>1899) possible=0;
        }

        if(!possible) cout << "Impossible" << endl;
        else cout << start+finaldiff << endl;
    }

    return 0;
}
