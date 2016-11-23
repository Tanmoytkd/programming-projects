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
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;

int p[20*100000/2+5];
int N, sum;
int w[25];

int main() {
    sf1(N);
    int sum=0;
    memset(p,0,sizeof(p));
    for(int i = 0; i < N; i++){
        sf1(w[i]);
        sum += w[i];
    }
    sort(w,w+N);
    for(int i = 0; i < N; i++)
        for(int j=sum/2;j>=w[i];j--)
            p[j]=max(p[j],p[j-w[i]]+w[i]);
    cout<<sum-2*p[sum/2]<<endl;
}
