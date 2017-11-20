#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char str1[100000], str2[100000];
    while(scanf("%s %s", str1, str2)!=EOF) {
        int len1=strlen(str1), len2=strlen(str2), pos=0, i;
        for(i=0; i<len2; i++) {
            if(str2[i]==str1[pos]) {
                pos++;
                if(pos==len1) break;
            }
        }
        if(pos==len1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
