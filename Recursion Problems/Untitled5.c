#include<stdio.h>
int main()
{
    char a[500];
    gets(a);
    int l=strlen(a),c=0;
    int i;
    for(i=0;i<l;i++)
    {
        if(a[i]==' ')
            c++;
    }
    printf("%d\n",c+1);
    return 0;
}

