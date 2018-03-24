#include <stdio.h>
#include <string.h>


int ar[2000][2000];

int max(int a, int b) {
	if(a>b) return a;
	else return b;
}

int main()
{
    char a[2000], b[2000];
    while(gets(a)!=NULL && gets(b)!=NULL)
    {
        int x=strlen(a),y=strlen(b);
        int i, j;
        for(i=0; i<x; i++)
            for(j=0; j<y; j++)
                ar[i][j]=0;


        for(i=0; i<x; i++)
            for(j=0; j<y; j++)
            {
                if(i==0 && j==0)
                {
                    if(a[i]==b[j]) ar[i][j]=1;
                    else ar[i][j]=0;
                }
                else if(i==0)
                {
                    if(a[i]==b[j]) ar[i][j]=1;
                    else ar[i][j]=ar[i][j-1];
                }
                else if(j==0)
                {
                    if(a[i]==b[j]) ar[i][j]=1;
                    else ar[i][j]=ar[i-1][j];
                }
                else
                {
                    if(a[i]==b[j])
                        ar[i][j]=ar[i-1][j-1]+1;
                    else
                        ar[i][j]=max(ar[i][j-1],ar[i-1][j]);
                }

            }
        if(x==0 || y==0) puts("0");
        else printf("%d\n", ar[x-1][y-1]);
    }
    return 0;
}


