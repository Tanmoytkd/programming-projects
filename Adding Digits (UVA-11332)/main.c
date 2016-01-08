#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=0;
    while(scanf("%d", &num) && num!=0) {
        int sum=0;
        while(num) {
            sum+=num%10;
            num/=10;
            sum = (sum<10) ? sum:(sum/10+sum%10);
        }
        printf("%d\n", sum);
    }
    return 0;
}
