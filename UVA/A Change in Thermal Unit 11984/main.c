#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test, i;
    scanf("%d", &test);
    for(i=1; i<=test; i++) {
        double c, f, res;
        scanf("%lf %lf", &c, &f);
        res = c + 5*f/9;
        printf("Case %d: %.2f\n", i, res);
    }
    return 0;
}
