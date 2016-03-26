#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char str[1000];
    while(gets(str)!=NULL) {
        int size = strlen(str), i;

        for(i=0; i<size; i++) {
            printf("%c", str[i]-7);
        }

        printf("\n");
    }
    return 0;
}
