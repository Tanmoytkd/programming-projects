#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test, i, r1, c1, r2, c2, res;
    scanf("%d", &test);
    for(i=1; i<=test; i++) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int row=abs(r1-r2), col=abs(c1-c2);
        res = (row>col) ? row:col;
        printf("Case %d: %d\n", i, res);
    }
    return 0;
}
