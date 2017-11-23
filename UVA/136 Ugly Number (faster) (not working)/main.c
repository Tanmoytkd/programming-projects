#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n=1, count=1;
    printf("The 1500'th ugly number is ");
    while(1) {
        printf("%lld\n", n);

        long long n2=n*2;
        count++;
        if(count==1500) {
            printf("%lld", n2);
            break;
        }

        long long n3=n*3;
        count++;
        if(count==1500) {
            printf("%lld", n3);
            break;
        }

        long long n4=n*4;
        count++;
        if(count==1500) {
            printf("%lld", n4);
            break;
        }

        long long n5=n*5;
        count++;
        if(count==1500) {
            printf("%lld", n5);
            break;
        }

        long long n6=n*6;
        count++;
        if(count==1500) {
            printf("%lld", n6);
            break;
        }

        long long n8=n*8;
        count++;
        if(count==1500) {
            printf("%lld", n8);
            break;
        }

        long long n9=n*9;
        count++;
        if(count==1500) {
            printf("%lld", n9);
            break;
        }

        long long n10=n*10;
        count++;
        if(count==1500) {
            printf("%lld", n10);
            break;
        }

        long long n12=n*12;
        count++;
        if(count==1500) {
            printf("%lld", n12);
            break;
        }

        long long n15=n*15;
        count++;
        if(count==1500) {
            printf("%lld", n15);
            break;
        }

        long long n16=n*16;
        count++;
        if(count==1500) {
            printf("%lld", n16);
            break;
        }

        long long n18=n*18;
        count++;
        if(count==1500) {
            printf("%lld", n18);
            break;
        }

        long long n20=n*20;
        count++;
        if(count==1500) {
            printf("%lld", n20);
            break;
        }

        long long n24=n*24;
        count++;
        if(count==1500) {
            printf("%lld", n24);
            break;
        }

        long long n25=n*25;
        count++;
        if(count==1500) {
            printf("%lld", n25);
            break;
        }

        long long n27=n*27;
        count++;
        if(count==1500) {
            printf("%lld", n27);
            break;
        }

        n=n*30;
        count++;
        if(count==1500) {
            printf("%lld", n);
            break;
        }
    }

    printf(".\n");
    return 0;
}
