#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char str[1001];

    int len;

    while(scanf("%s", str)!=EOF) {
        int sum1=0, sum2=0, i=0, len=strlen(str);

        for(i=0; i<len; i++) {
            char ch=str[i];
            if(i&1) sum1+=ch-'0';
            else sum2+=ch-'0';
        }
        if(sum1==0 && sum2==0) break;

        int diff=abs(sum1-sum2);

        if(diff%11==0) printf("%s is a multiple of 11.\n", str);
        else printf("%s is not a multiple of 11.\n", str);
    }
    return 0;
}
