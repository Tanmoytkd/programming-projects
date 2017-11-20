#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long i=1, count=0, ugly;

    for(i=1; count!=1500; i++) {
        int temp=i;
        while(temp&1 == 0) temp/=2;
        while(temp%3 == 0) temp/=3;
        while(temp%5 == 0) temp/=5;

        if(temp==1){
            ugly=i;
            count++;
            printf("%lld : %lld\n", count, ugly);
        }
    }

    printf("The 1500'th ugly number is %lld.\n", ugly);

    return 0;
}
