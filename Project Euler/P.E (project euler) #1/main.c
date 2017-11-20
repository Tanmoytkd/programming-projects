#include <stdio.h>
#include <stdlib.h>

int multiples(int n, int limit);

int main()
{
    int sum=0;
    sum+=multiples(3,  1000);
    sum+=multiples(5,  1000);
    sum-=multiples(15, 1000);
    printf("Sum=%d", sum);
    return 0;
}

int multiples(int n, int limit) {
    int sum = 0, multi=0;
    for(multi=n; multi<limit; multi+=n) {
        sum +=multi;
    }
    //printf("%d\n",sum);
    return sum;
}
