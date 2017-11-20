#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    for(x=1; x<=200; x++) {
        if(x%2==1) {
            printf("odd= %d\t", x);
        }
        else {
            printf("even= %d\n", x);
        }
    }
    return 0;
}
