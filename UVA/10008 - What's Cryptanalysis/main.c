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
    int testcase, i, len, pos;
    char str[256], occur[26], letters[26];
    for(i=0; i<26; i++) {
        occur[i]=0;
        letters[i]=i;
    }

    scanf("%d", &testcase);

    while(testcase-->-1) {
        gets(str);
        len=strlen(str);

        while(--len>-1) {
            if(isalpha(str[len])) {
                pos= toupper(str[len])-'A';
                occur[pos]++;
            }
        }
    }

    for(i=1; i<26; i++) {
        int x=i;
        while(x!=0 && occur[x]>occur[x-1]) {
            int temp=occur[x];
            occur[x]=occur[x-1];
            occur[x-1]=temp;

            temp=letters[x];
            letters[x]=letters[x-1];
            letters[x-1]=temp;

            x--;
        }
    }

    for(i=0; i<26; i++) {
        if(occur[i]!=0) {
            printf("%c %d\n", letters[i]+'A', occur[i]);
        }
    }

    return 0;
}
