#include<stdio.h>

int main()
{
    int i,n,a,b,value,sum;

    printf("Please enter the number of values you want: ");
    scanf("%d", &n);

    a=1;
    b=1;
    sum=a+b;
    if(n==1)
    {
        printf("The Sum is 1");
    }
    else
    {
        for(i=3; i<=n; i++)
        {
            value=a+b;
            sum=sum+value;
            a=b;
            b=value;
        }
        printf("The Sum is %d",sum);
    }

    return 0;
}
