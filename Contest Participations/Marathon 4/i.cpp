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
#define FOR(I, N) for(int I=0; I<N; I++)
#define FOR1(I, N) for(int I=1; I<=N; I++)

#define mx 60000
#define w 1000000007
#define ul   long long int
using namespace std;
  long long ara[mx];
  long long prime[mx/2+7];
  long long len=0;

void sieve()
{
      long long i,j,a,b;

    for(i=3; i*i<=46700; i+=2)
    {
        if(ara[i]==0)
        {
            for(j=i*i; j<=46700; j+=2*i)
            {
                ara[j]=1;

            }
        }
    }

    prime[++len]=2;
    for( i=3; i<=mx; i+=2)
    {
        if(ara[i]==0)
        {
            prime[++len]=i;
        }
    }
    return;
}
ul bigmod(ul x,ul y)
{
    ul b,store;
    if(y==0)
        return 1;
    if(y==1)
        return (x)%w;

    if(y%2==1)
    {
        b=bigmod(x,y-1)%w;
        return ((b*x)%w);
    }

    if(y%2==0)
    {
        store=bigmod(x,y/2)%w;
        return (store*store)%w;
    }
}
int main()
{
    sieve();
      long long num,b,c,n,m,v,g,o,x,k,a,l=1,temp;
    scanf("%lld",&g);
    while(g--)
    {
        b=0,n=1;
        scanf("%lld %lld",&num,&o);
        v=num;
        for(  long long i=1; i<=len && prime[i]*prime[i]<=v; i++)
        {
            c=0;
            if(num%prime[i]==0)
            {
                c=0;
                while(num%prime[i]==0)
                {
                    c++;
                    num/=prime[i];
                }

                m=bigmod(prime[i],(c*o)+1);
                a=(m-1+w)%w;
                k=bigmod(prime[i]-1,w-2);
                temp=(a*k)%w;
                n=(temp*n)%w;
            }

        }

        if(num!=1)
        {
            c=1;
            m=bigmod(num, (c*o)+1);
            a=(m-1+w)%w;
            k=bigmod(num-1, w-2);
            temp=(a*k)%w;
            n=(temp*n)%w;
        }
        x=n%w;
        printf("Case %lld: %lld\n",l++,x);
    }
}
