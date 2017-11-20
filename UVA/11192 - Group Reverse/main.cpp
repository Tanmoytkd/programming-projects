#include<stdio.h>
#include<string.h>

int main()
{

    int i,j,k,l,n,tmp;
    char a[105];

    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        scanf("%s",a);
        l=strlen(a);
        int group = l/n;
        for(i=0; i<l; i+=group)
        {
            j=i+group-1;
            k=i;
            while(k<j)
            {
                tmp=a[k];
                a[k]=a[j];
                a[j]=tmp;
                k++;
                j--;
            }
        }

        printf("%s\n",a);
    }
    return 0;
}
