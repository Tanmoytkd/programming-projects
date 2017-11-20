#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T, i, ls, d=0;
    char s[150], p;

    scanf("%d", &T);

    scanf("%s", s);
    //gets(s);
    //scanf("%c", &p);
    p=getchar(); //input the newline character
    p=getchar(); //input the real character
    ls=strlen(s);

    puts(s);
    printf("\'%c\'",p);
    return 0;
}
