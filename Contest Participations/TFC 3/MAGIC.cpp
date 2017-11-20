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


int main()
{
    int board[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cin >> board[i][j];
        }
    }

    int a, b, c, d, e, f, g, h, x, y, z;
    a=board[0][1];
    b=board[0][2];
    c=board[1][0];
    d=board[1][2];
    e=board[2][0];
    f=board[2][1];

    x=(2*e+f-a)/2;
    z=(2*b-f+a)/2;
    y=a+b-z;

    board[0][0]=x;
    board[1][1]=y;
    board[2][2]=z;

    for(int i=0; i<3; i++) {
        cout << board[i][0];
        for(int j=1; j<3; j++) {
            cout << " " << board[i][j];
        }
        cout << endl;
    }
    return 0;
}