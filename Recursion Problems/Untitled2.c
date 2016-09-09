#include<stdio.h>
int main()
{
    int n,c=1;
    scanf("%d",&n);
    int i;
    for(i=1; i<=n; i++)
    {
        int j;
        for(j=i; j<n; j++)
        {
            printf(" ");
        }
        printf("%d",i);
        if(i!=1)
        {
            int k = 0;
            for(k=1; k<=c; k++)
            {
                printf(" ");
            }
            c+=2;
            printf("%d",i);
        }
        printf("\n");
    }
    int d=c-4;
    c=1;
    for(i=n-1; i>=1; i--)
    {
        int j;
        for(j=1; j<=c; j++)
        {
            printf(" ");
        }
        c++;
        printf("%d",i);
        if(i!=1)
        {
            int k;
            for(k=1; k<=d; k++)
            {
                printf(" ");
            }
            d=d-2;
            printf("%d\n",i);
        }
    }


    return 0;
}

