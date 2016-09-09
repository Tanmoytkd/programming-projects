#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arra[n+5];
    int i;
    for(i=0;i<n;i++)
    {

        scanf("%d",&arra[i]);
    }
    for(i=0;i<n;i++)
    {
        int j;
        for(j=1;j<n;j++)
        {
            if(arra[j]<arra[j-1])
            {
                int temp=arra[j];
                arra[j]=arra[j-1];
                arra[j-1]=temp;
            }
        }
    }
    int difference=arra[n-1]-arra[0];
    printf("%d\n",difference);
    return 0;
}
