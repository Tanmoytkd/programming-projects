#include<stdio.h>
#include<string.h>
int main()
{
#ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i,k,l,n;

    char a[4],b[4];
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%s%s",a,b);
        if((a[0]=='J' && a[1]=='A') || (a[0]=='M' && a[2]=='R') || (a[0]=='M' && a[2]=='Y') || (a[0]=='A' && a[2]=='G') || (a[0]=='J'&& a[2]=='L') || (a[0]=='O') || (a[0]=='D'))
            k=31;
        else if(a[0]=='F')
            k=28;
        else
            k=30;


        if(b[0]=='S' && b[1]=='U')
            l=1;
        else  if(b[0]=='M')
            l=2;
        else  if(b[0]=='T'&& b[1]=='U')
            l=3;

        else if(b[0]=='W')
            l=4;
        else  if (b[0]=='T' && b[1]=='H')
            l=5;
        else if(b[0]=='F')
            l=6;
        else
            l=7;

        int friday= (l<=6) ? 6-l+1 : 13-l+1;
        int saturday= 7-l+1, weekend=0;

        while(friday<=k)
        {
            friday+=7;
            weekend++;
        }

        while(saturday<=k)
        {
            saturday+=7;
            weekend++;
        }

        printf("%d\n", weekend);
    }

    return 0;
}
