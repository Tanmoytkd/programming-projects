#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s, t, v;
    while(scanf("%d %d", &v, &t)==2) {
        if(t==0) printf("0\n");
        else {
            s= v*t*2;
            printf("%d\n", s);
        }
    }
    return 0;
}
