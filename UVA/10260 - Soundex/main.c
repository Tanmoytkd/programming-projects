#include <stdio.h>
#include <stdlib.h>

int soundex(char ch) {
    switch(ch) {
        case 'B':
        case 'F':
        case 'P':
        case 'V': return 1;
        case 'C':
        case 'G':
        case 'J':
        case 'K':
        case 'Q':
        case 'S':
        case 'X':
        case 'Z': return 2;
        case 'D':
        case 'T': return 3;
        case 'L': return 4;
        case 'M':
        case 'N': return 5;
        case 'R': return 6;
    }
    return 0;
}

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    char str[30];
    while(gets(str)!=NULL) {
        int len=strlen(str), i;
        for(i=0; i<len; i++) {
            int value=soundex(str[i]);
            if(value!=0 && (i==0 || value!=soundex(str[i-1]))) {
                printf("%d", value);
            }
        }
        printf("\n");
    }

    return 0;
}
