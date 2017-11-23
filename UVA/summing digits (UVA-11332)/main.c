#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for(i=1; i<99999999; i++) {
        int num1=i, num2=i, sum1=0, sum2=0;
        while(num1) {
            sum1+=num1%10;
            num1/=10;
            sum1= (sum1>=10) ? (1+sum1%10):sum1;
        }
        printf("%d: %d\t", i, sum1);

        if(num2<10) {
                sum2=num2;
                printf("%d\t", sum2);
        }
        else {
                while(num2>9) {
                    sum2=0;
                    while(num2) {
                        sum2+=num2%10;
                        num2/=10;
                    }
                    num2=sum2;
            }
            printf("%d\t", sum2);
        }

        if(sum1==sum2) printf("same\n");
        else printf("not same\n");
        //system("pause");
    }
    return 0;
}
