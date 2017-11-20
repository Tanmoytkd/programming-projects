#include<stdio.h>

int main()
{
    int testcase;
    scanf("%d", &testcase);
    int m;
    for(m=1; m<=testcase; m++)
    {

        int n,i,sum=0;
        scanf("%d", &n);

        for(i=1; i<=n; i++)
        {
            int x=i;
            while(x%5==0)
            {
                sum++;
                x=x/5;
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
