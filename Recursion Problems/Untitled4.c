#include<stdio.h>
int main()
{
    char a[12];
    gets(a);
    if(a[2]=='6')
    {
        printf("Airtel\n");
    }
    else if(a[2]=='7')
    {
        printf("Grameenphone\n");
    }
    else{
        printf("Teletalk\n");
    }
    return 0;
}
