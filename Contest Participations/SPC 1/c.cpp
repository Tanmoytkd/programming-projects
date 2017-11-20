#include<bits/stdc++.h>
using namespace std;
typedef long long int lint;

char str[100101];
int main()
{
    int t,len,i,j,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        len = strlen(str);
        for(i=0; i<len/2; i++)
        {
            j = len - 1 -i;
            if(str[i]!=str[j])
                break;
        }
        if(i==len/2)
        {
            if(len%2==1)
            {
                printf("%d\n",len/2);
                continue;
            }
        }
        {
            x=i+1;
            y=j;
            while(x<y)
            {
                if(str[x]!=str[y])
                    break;
                x++;
                y--;
            }

            if(x>=y)
            {
                printf("%d\n",i);
            }
            else
            {
                x=i;
                y=j-1;
                while(x<y)
                {
                    if(str[x]!=str[y])
                        break;
                    x++;
                    y--;
                }

                if(x>=y)
                {
                    printf("%d\n",j);
                }
                else
                {
                    printf("-1\n");
                }
            }
        }
    }
    return 0;
}
