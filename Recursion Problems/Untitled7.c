
#include<stdio.h>
int main()
{
    char a[500];
    gets(a);
    int l=strlen(a),c=0;
    int i,j;
    for(i=0,j=l-1;i<l/2;i++,j--)
    {
        if(a[i]!=a[j])
        {
            c=1;
            break;
        }
    }
    if(c==0)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}
