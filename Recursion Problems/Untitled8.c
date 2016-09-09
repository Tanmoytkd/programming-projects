
#include<stdio.h>
int main()
{
    char a[500],b[500];
    scanf("%s",a);
    scanf("%s",b);
    int l=strlen(a),c=0;
    int i;
    for(i=0;i<l;i++)
    {
        if(a[i]==b[i]||a[i]==b[i]+32||a[i]+32==b[i])
        {
            c=0;
        }
        else{
            c=1;
            break;
        }
    }
    if(c==0)
        printf("Same\n");
    else
        printf("Not Same\n");
    return 0;
}

