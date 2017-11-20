#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int testcase, i, first=1;
    scanf("%d", &testcase);

    for(; testcase; testcase--) {
        int len, a, b, sum, carry=0;
        scanf("%d", &len);
        char num1[len+1], num2[len+1], num3[len+1];
        num1[0]=0;
        num2[0]=0;

        for(i=1; i<=len; i++) {
            scanf("%d %d", &a, &b);

            num1[i]=a;
            num2[i]=b;
        }

        for(i=len; i>=0; i--) {
            sum=num1[i]+num2[i]+carry;
            carry=sum/10;
            sum=sum%10;

            num3[i]=sum;
        }

        if(first==1) first=0;
        else {
            printf("\n");
        }

        for(i=0; num3[i]==0; i++);
        for(; i<=len; i++) {
            printf("%d", num3[i]);
        }
        printf("\n");
    }
    return 0;
}
