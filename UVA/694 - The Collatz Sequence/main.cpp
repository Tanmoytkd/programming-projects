#include<stdio.h>
int main()
{
    long long n,i,a=1,b,m;
    while(1)
    {
        scanf("%lld%lld",&n,&m);
        if(n<0 && m<0)
            break;

        b=n;
        i=1;

        for(;;)
        {
            if(n==1)
                break;
            else if(n>m) {
                i--;
                break;
            }
            else if(n%2==0)
                n=n/2;
            else
                n=3*n+1;
            i++;
        }

        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",a,b,m,i);
        a++;
    }
    return 0;
}
