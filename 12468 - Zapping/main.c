#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int a, b;
    scanf("%d %d", &a, &b);

    while(a!=-1 && b!=-1) {
        int diff = abs(a-b);
        if(diff>50) diff=100-diff;
        printf("%d\n", diff);

        scanf("%d %d", &a, &b);
    }

    return 0;
}
