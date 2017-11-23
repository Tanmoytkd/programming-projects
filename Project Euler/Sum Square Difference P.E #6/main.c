#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, sum=0, sqsum=0;
    for(i=1; i<=100; i++) {
        sum += i;
        printf("%d\t", sum);
        sqsum += i*i;
        printf("%d\n", sqsum);
    }
    sum = sum * sum;
    int res = ((sum-sqsum)>=0) ? sum - sqsum : sqsum - sum;
    printf("\n%d\n", res);
    return 0;
}
