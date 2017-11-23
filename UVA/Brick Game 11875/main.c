#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test, i, j;
    scanf("%d", &test);

    for(i=1; i<=test; i++) {
        int number, value, resultpos;
        scanf("%d", &number);
        resultpos=(number+1)/2;
        for(j=1; j<=number; j++) {
            scanf("%d", &value);
            if(j==resultpos) {
                printf("Case %d: %d\n", i, value);
            }
        }
    }
    return 0;
}
