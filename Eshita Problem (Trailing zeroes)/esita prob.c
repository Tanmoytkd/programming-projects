#include<stdio.h>
int main()
{
    int n=200,i,j=0,x,sum=0;

for(i=1;i<=n;i++)
{
    if(i%5==0){
        x=i;
        for(;;)
        {

            if(x%5==0){j++;x=x/5;}
            else break;
        }

    }



}
printf("%d\n",j);

return 0;

}
