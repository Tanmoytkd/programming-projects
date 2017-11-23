#include<stdio.h>
#include<math.h>
#define n 1000000
char primes[n];
void sieve()
{
    long i;
    for(i=2;i<=n;i++)
    {
        primes[i]=1;
    }
    primes[0]=0;
    primes[1]=0;
    long len=sqrt(n);
    long j;
    for(j=2;j<=len;j++)
    {
        if(primes[j])
        {
            for(i=2;i*j<=n;i++)
            {
                primes[i*j]=0;
            }
        }
        primes[2]=1;
    }
}

    int main()
    {
        long p,b,a;
        sieve();
        while(scanf("%ld",&p) && p)
        {
            for(a=3;a<=p;a++)
            {
                if(primes[a])
                {
                    b=p-a;
                    if(primes[b])
                    {
                        printf("%ld = %ld + %ld\n",p,a,b);
                        break;
                    }
                }
            }
        }
    return 0;
    }

