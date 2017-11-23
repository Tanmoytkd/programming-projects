#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long int testcase, i;
    scanf("%lld", &testcase);
    for(i=0; i<testcase; i++) {
        long long int farmers, sum=0, farm, animals, echo, j;
        scanf("%lld", &farmers);
        for(j=0; j<farmers; j++) {
            scanf("%lld %lld %lld", &farm, &animals, &echo);
            sum += farm*echo;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
