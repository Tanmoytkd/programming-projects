#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0, sum=0;
    while(scanf("%d", &n) && n!=0) {
        if(n<10) { printf("%d\n", n); }
        else {
            while(n>9) {
            sum=0;
            while(n) {
                sum+=n%10;
                n/=10;
            }
            n=sum;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
