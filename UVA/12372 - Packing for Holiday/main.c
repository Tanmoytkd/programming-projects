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
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a>20 || b>20 || c>20) printf("Case %d: bad\n", i);
        else printf("Case %d: good\n", i);
    }

    return 0;
}
