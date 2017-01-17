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

    int arr[n+1];
    int total=0, nonzero=0;
    FOR1(i, n) {
        sf1(arr[i]);
        total+=arr[i];
        nonzero+=(arr[i]!=0);
    }

    int part=-1;

    if(!nonzero) {
        cout << "NO" << endl;
    }
    else {
        if(total!=0) {
            cout << "YES" << endl;
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
        }
        else {
            cout << "YES" << endl;
            cout << 2 << endl;
            FOR1(i, n) {
                if(arr[i]!=0) {
                    part=i;
                    break;
                }
            }
            cout << 1 << " " << part << endl;
            cout << part+1 << " " << n << endl;
        }
    }

    return 0;
}
