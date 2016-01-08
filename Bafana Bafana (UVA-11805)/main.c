#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d", &test);
    int i;
    for(i=1; i<=test; i++) {
        int N, K, P;
        scanf("%d %d %d", &N, &K, &P);
        int result=(K+P)%N;
        result = (result!=0) ? result:N;
        printf("Case %d: %d\n", i, result);
    }
    return 0;
}
