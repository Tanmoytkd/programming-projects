#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int num1,num2,rem1,rem2,rem3;
    while(1){
        scanf("%d%d",&num1,&num2);
        if(num1==0 && num2==0)
            break;
        else{
            int count2=0, rem=0;
            while(num1>0 || num2>0){
                rem1=num1%10;
                rem2=num2%10;
                rem3=rem+rem1+rem2;
                if(rem3>9){
                    count2++;
                    rem=1;
                }
                else rem=0;

                num1=num1/10;
                num2=num2/10;
            }
            if(count2==0)
                printf("No carry operation.\n");
            else if(count2==1)
                printf("1 carry operation.\n");
            else
                printf("%d carry operations.\n",count2);
        }
    }

    return 0;
}
