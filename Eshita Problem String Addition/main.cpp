#include<stdio.h>
#include<string.h>

int main()
{
    char str1[300],str2[300],sum[300];



    int i,n,j,x,y,l;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",str1);
        scanf("%s",str2);

        strrev(str1);
        strrev(str2);

        for(i=299; i>=0; i--) sum[i]='0';

        int carry=0, sumdig=0, k=299;

        for(i=strlen(str1)-1, j=strlen(str2)-1; i>=0 && j>=0; i--, j--)
        {
            x=str1[i]-'0';
            y=str2[j]-'0';

            sumdig=x+y+carry;
            carry=sumdig/10;

            sum[k]=sumdig%10;
            k--;
        }

        for(; i>=0; i--) {
            x=str1[i]-'0';
            sumdig=x+carry;
            carry=sumdig/10;

            sum[k]=sumdig%10;
            k--;
        }

        for(; j>=0; j--) {
            y=str2[j]-'0';
            sumdig=y+carry;
            carry=sumdig/10;

            sum[k]=sumdig%10;
            k--;
        }

        sum[k]=carry;

    }

    for(i=0; i<299; i++) {
        if(sum[i]!='0') break;
    }


    for(j=299; j>=i; j--) {
       printf("%c",sum[j]);
    }
    printf("\n");

    return 0;
}
