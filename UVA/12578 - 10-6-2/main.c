#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int test, i;
    scanf("%d", &test);
    for(i=1; i<=test; i++) {
        double len, rect, circle, green;
        scanf("%lf", &len);
        rect=len*len*6/10;
        circle=acos(-1)*len*len/25;
        green = rect-circle;
        printf("%.2lf %.2lf\n", circle, green);
    }
    return 0;
}
