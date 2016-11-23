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

bool func(int a, int b) {
    return a>b;
}
int main()
{
    int a,b,c,d,e,y,i,f,m,j,k,x;
    while(1)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==0&&b==0&&c==0)break;
        int ara[a],arr[a],sum=0;;
        for( i=0 ; i<a; i++)
        {
            scanf("%d",&ara[i]);

        }
        sort(ara,ara+a);

        for( i=0 ; i<a; i++)
        {
            scanf("%d",&arr[i]);

        }
        sort(arr,arr+a,func);

        y=0;
        for(i=0; i<a; i++)
        {
            int sum=ara[i]+arr[i];
            if(sum>b)y+=sum-b;
        }
        printf("%d\n",y*c);
    }
    return 0;
}
