#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digit_count(char ch) {
    switch(ch) {
        case 'a':
        case 'd':
        case 'g':
        case 'j':
        case 'm':
        case 'p':
        case 't':
        case 'w':
        case ' ': return 1;
        case 'b':
        case 'e':
        case 'h':
        case 'k':
        case 'n':
        case 'q':
        case 'u':
        case 'x': return 2;
        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'r':
        case 'v':
        case 'y': return 3;
        case 's':
        case 'z': return 4;
        default : return 1;
    }
}

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int testcase, i;
    char str[101];
    scanf("%d", &testcase);
    gets(str);

    for(i=1; i<=testcase; i++) {
        gets(str);
        int sum=0, len=strlen(str), j;

        for(j=0; j<len; j++) {
            sum+=digit_count(str[j]);
        }
        printf("Case #%d: %d\n", i, sum);
    }

    return 0;
}
