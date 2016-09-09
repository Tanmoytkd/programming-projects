#include<stdio.h>
int main()
{
    int r,c,max;
    scanf("%d%d",&r,&c);
    int a[r+5][c+5];
    int i;
    for(i=0; i<r; i++)
    {
        int j;
        for(j=0; j<c; j++)
        {

            scanf("%d",&a[i][j]);
        }
    }

    for(i=0; i<c; i++)
    {
        max=0;
        int j;
        for(j=0; j<r; j++)
        {
            if(a[j][i]>max)
            {
                max=a[j][i];
            }
        }
        printf("Column %d - %d\n",i+1,max);
    }
    return 0;
}

