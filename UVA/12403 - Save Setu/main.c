#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int test, sum=0, i;
    char str[1000];
    scanf("%d", &test);
    fflush(stdin);
    for(i=1; i<=test; i++) {
        gets(str);
        fflush(stdin);
        if(str[0]=='r') printf("%d\n", sum);
        else {
            int money=0, j, len=strlen(str);
            for(j=7; j<len; j++) {
                money =  money*10 + (str[j]-'0');
            }
            sum+=money;
        }
    }

    return 0;
}
