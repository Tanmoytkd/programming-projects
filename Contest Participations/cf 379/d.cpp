/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%I64d", &x)
#define sf2(x,y) scanf("%I64d %I64d", &x, &y)
#define sf3(x,y,z) scanf("%I64d %I64d %I64d", &x, &y, &z)
#define pf1(x) printf("%I64d\n", x)
#define PI acos(-1.00)
#define FOR(I, N) for(long long I=0; I<N; I++)
#define FOR1(I, N) for(long long I=1; I<=N; I++)

using namespace std;

struct piece {
    char ptype;

    piece() {
    ptype='Z';
    }
};

typedef long long lint;

lint dist[10];
piece p[10];

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    FOR(i, 10) dist[i]=LLONG_MAX;
    cout << LLONG_MAX << endl;

    lint n;
    sf1(n);

    lint a,b;
    sf2(a,b);


    while(n--) {
        char ch;
        lint x, y;

        cin >> ch;
        while(!isalpha(ch)) cin >> ch;
        sf2(x,y);

        int type=0;
        if(a>x && b>y && a-x==b-y) type=1;
        else if(a>x && b==y) type=2;
        else if(a>x && b<y && a-x==y-b) type=3;
        else if(x==a && y<b) type=4;
        else if(x==a && y>b) type=5;
        else if(x>a && b>y && x-a==b-y) type=6;
        else if(x>a && b==y) type=7;
        else if(x>a && y>b && x-a==y-b) type=7;

        if(type==0) continue;
        lint distance=max(llabs(x-a), llabs(y-b));

        if(distance<dist[type]) {
            dist[type]=distance;
            p[type].ptype=ch;
        }
    }

    lint check=0;
    if(p[1].ptype=='B'||p[1].ptype=='Q') check=1;
    if(p[2].ptype=='R'||p[2].ptype=='Q') check=1;
    if(p[3].ptype=='B'||p[3].ptype=='Q') check=1;
    if(p[4].ptype=='R'||p[4].ptype=='Q') check=1;
    if(p[5].ptype=='R'||p[5].ptype=='Q') check=1;
    if(p[6].ptype=='B'||p[6].ptype=='Q') check=1;
    if(p[7].ptype=='R'||p[7].ptype=='Q') check=1;
    if(p[8].ptype=='B'||p[8].ptype=='Q') check=1;


    if(check==0) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
