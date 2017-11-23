#include <bits/stdc++.h>
using namespace std;
#define mx 110

char A[mx], B[mx];

void LCS(int m,int n)
{
   int lcs[m+1][n+1];

   char dir[m+1][n+1];
   char strLCS[mx], ans[mx*2];

   for(int i=0; i<=m; ++i) {
      for(int j=0; j<=n; ++j) {
         if(i==0 || j==0) lcs[i][j]=0;
         else if(A[i-1]==B[j-1]) {
            lcs[i][j]=lcs[i-1][j-1] + 1;
            dir[i][j]=11;
         }
         else {
           		if(lcs[i-1][j]>=lcs[i][j-1]) {
           			lcs[i][j]=lcs[i-1][j];
           			dir[i][j]=10;
           		}
           		else {
           			lcs[i][j]=lcs[i][j-1];
           			dir[i][j]=01;
           		}
           }
      }
   }

    int i=m,j=n;
    int ipos=0;
    while(1)
    {
    	if(i==0 || j==0) break;
    	if(dir[i][j]==11)
    	{
    	    i--;
    		strLCS[ipos++]=A[i];
    		j--;
      	}
    	else if(dir[i][j]==10) i--;
    	else j--;
    }

    i=m-1; j=n-1;
    int l=0,k=0;
    while(i>=0 || j>=0) {
    	if(l<ipos) {
            while(j>=0 && strLCS[l]!=B[j])
                {
                    ans[k++]=B[j--];
                }

                while(i>=0 && strLCS[l]!=A[i]) {
                    ans[k++]=A[i--];
                }

    		ans[k++]=strLCS[l++];
    		j--;
    		i--;

       }
       else {
            while(j>=0) {
                ans[k++]=B[j--];
            }
            while(i>=0) {
                ans[k++]=A[i--];
            }
       }
    }

    for(i=k-1;i>=0;--i)
    	printf("%c",ans[i]);
    printf("\n");
}

int main() {
   while(scanf("%s%s",A,B)!=EOF)
   {
      int l1=strlen(A), l2=strlen(B);
      LCS(l1, l2);
   }
   return 0;
}
