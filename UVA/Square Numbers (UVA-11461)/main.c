#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, j=0;
    while(scanf("%d %d", &i, &j) && (i!=0 || j!=0)) {
        int m, count=0;
        for(m=0; m*m<=j; m++) {
            if(m*m>=i) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
