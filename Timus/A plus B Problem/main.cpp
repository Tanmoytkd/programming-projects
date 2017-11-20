#include <stdio.h>

int main()
{
    int a , b, res;
    while(scanf("%d %d", &a, &b)==2) {
        res=a+b;
        printf("%d\n", res);
    }
    return 0;
}
