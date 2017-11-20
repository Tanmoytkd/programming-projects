#include<stdio.h>
int main()
{
    long long int n,r;
    for(;;)
    {
        r=0;
        scanf("%lld",&n);
        if(n==0) break;

        for(;;){
            while(n>0)
            {
                r=r+(n%10);
                n/=10;
            }

            if(r>9)
            {
                n=r;
                r=0;
            }
            else break;
       }
       printf("%lld\n",r);
    }
    return 0;
}
