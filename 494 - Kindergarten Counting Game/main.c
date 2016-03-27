#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char str[10000];
    while(gets(str)!=NULL) {
        int len=strlen(str), i, counter=0;

        for(i=0; i<len; i++) {
            char ch=str[i];
            if(isalpha(ch)) {
                if(i==0) counter++;
                else {
                    if(isalpha(str[i-1])==0) counter++;
                }
            }
        }

        printf("%d\n", counter);
    }
    return 0;
}
