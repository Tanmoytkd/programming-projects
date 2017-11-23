#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double n, p, result;
    while(scanf("%lf %lf", &n, &p)==2) {
        result=pow(p, 1/n);
        printf("%.0lf\n", result);
    }
    return 0;
}
