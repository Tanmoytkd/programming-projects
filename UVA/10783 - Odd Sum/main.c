#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test=0, i;
    scanf("%d", &test);
    for(i=1; i<=test; i++) {
        int a=0, b=0, sum=0;
        scanf("%d\n%d", &a, &b);
        if(a%2==0) a++;
        while(a<=b) {
            sum+=a;
            a+=2;
        }
        printf("Case %d: %d\n", i, sum);
    }
    return 0;
}
