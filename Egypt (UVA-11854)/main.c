#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    while(a!=0 || b!=0 || c!=0) {
        if(a>b && a>c && a*a==(b*b+c*c)) printf("right\n");
        else if(b>a && b>c && b*b==a*a+c*c) printf("right\n");
        else if(c>a && c>b && c*c==a*a+b*b) printf("right\n");
        else printf("wrong\n");
        scanf("%d %d %d", &a, &b, &c);
    }
    return 0;
}
