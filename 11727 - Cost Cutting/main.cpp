#include<stdio.h>
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int times,a,b,c,i;
    scanf("%d",&times);
    for(i=1;i<=times;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if((a>=b && b>=c) || (c>=b && b>=a))
            printf("Case %d: %d\n",i,b);
        else if((b>=a && a>=c)|| (c>=a && a>=b))
            printf("Case %d: %d\n",i,a);
        else
            printf("Case %d: %d\n",i,c);
    }
    return 0;
}
