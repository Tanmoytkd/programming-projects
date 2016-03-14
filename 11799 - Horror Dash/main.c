#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int test, i;
    scanf("%d", &test);
    for(i=1; i<=test; i++) {
        int s, max, speed, j;
        scanf("%d", &s);
        scanf("%d", &max);

        for(j=1; j<s; j++) {
            scanf("%d", &speed);
            if(speed>max) max=speed;
        }

        printf("Case %d: %d\n", i, max);
    }
    return 0;
}
