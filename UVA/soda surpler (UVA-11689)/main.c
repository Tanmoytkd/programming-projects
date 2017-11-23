#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d", &test);
    int i;
    for(i=1; i<=test; i++) {
        int count=0, e, f, c;
        scanf("%d %d %d", &e, &f, &c);
        while((e+f)>=c) {
            int d=e+f;
            e=d%c;
            f=d/c;
            count+=f;
        }
        printf("%d\n", count);
    }
    return 0;
}
