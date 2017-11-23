/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100000];
    while(gets(str)) {
        int len=strlen(str);
        int spos=0, start=1;
        for(spos=0; spos<len; spos++) {
            char ch=str[spos];
            if(ch!='"') {
                printf("%c", ch);
            }
            else {
                if(start==1) {
                    start=0;
                    printf("``");
                }
                else {
                    start=1;
                    printf("''");
                }
            }
        }
        printf("\n");
    }
    return 0;
}*/

#include<stdio.h>
#include<string.h>
int main()
{
    char s[100000];
    long i,l,p=1;
    while(gets(s))
    {
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='"')
            {
                if(p==1)
                printf("``");
                else
                printf("''");
                p= (p==1) ? 0:1;
            }
            else
            printf("%c",s[i]);
        }
        printf("\n");

    }
    return 0;
}
