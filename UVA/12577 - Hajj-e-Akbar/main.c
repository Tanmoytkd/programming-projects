#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int count=1;
    char str[1000];
    while(gets(str)!=NULL) {
        if(str[0]=='*') break;
        else if(str[0]=='H') printf("Case %d: Hajj-e-Akbar\n", count);
        else printf("Case %d: Hajj-e-Asghar\n", count);
        count++;
    }
    return 0;
}
