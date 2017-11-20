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

int main ()
{
    int n, r;
    int tst = 0;

    while ( scanf ("%d %d", &n, &r) ) {
        if ( n == 0 && r == 0 ) break;

        map <string, int> cityIndex;
        string first, second;
        int cost;
        int index = 1;

        int d [205] [205];

        for ( int i = 0; i < 205; i++ ) {
            for ( int j = 0; j < 205; j++ ) d [i] [j] = -1;
            d [i] [i] = 0;
        }

        for ( int i = 0; i < r; i++ ) {
            cin >> first >> second >> cost;
            if ( !cityIndex [first] ) cityIndex [first] = index++;
            if ( !cityIndex [second] ) cityIndex [second] = index++;

            d [cityIndex [first]] [cityIndex [second]] = cost;
            d [cityIndex [second]] [cityIndex [first]] = cost;
        }

        for ( int k = 1; k <= n; k++ ) {
            for ( int i = 1; i <= n; i++ ) {
                for ( int j = 1; j <= n; j++ )
                    d [i] [j] = d [j] [i] = max (d [i] [j], min (d [i] [k], d [k] [j]));
            }
        }


        string source, dest;
        cin >> source >> dest;
        printf ("Scenario #%d\n", ++tst);
        printf ("%d tons\n\n", d [cityIndex [source] ] [cityIndex [dest]]);
    }

    return 0;
}
