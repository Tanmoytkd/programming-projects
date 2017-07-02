#include <bits/stdc++.h>
using namespace std;

void LCS(char *A, char *B,int m,int n)
{
   int lcs[m+1][n+1];

   /*This Dir[][] is used to store the direction
   using the element which we get the value of the
   present value of LCS*/

   char Dir[m+1][n+1];
   char LCSstring[102]; // stores the LCS string
   char ans[202]; //stores the final answer

   for(int i=0; i<=m; ++i)
      for(int j=0; j<=n; ++j)
      {

         if(i==0 || j==0)
            lcs[i][j]=0;
         else if(A[i-1]==B[j-1])
            {
            	/*Diagonally*/
            	lcs[i][j]=lcs[i-1][j-1] + 1;
        		Dir[i][j]='`';
            }
         else
           {
           		if(lcs[i-1][j]>=lcs[i][j-1])
           		{
           			/*From top*/
           			lcs[i][j]=lcs[i-1][j];
           			Dir[i][j]='|';
           		}
           		else
           		{
           			/*From left*/
           			lcs[i][j]=lcs[i][j-1];
           			Dir[i][j]='-';
           		}
           }
      }

    /*To store LCS
    The LCS is stored in reverse manner*/
    int i=m,j=n;
    int countv=0;
    while(1)
    {
    	if(i==0 || j==0)
    		break;
    	if(Dir[i][j]=='`')
    	{
    		LCSstring[countv++]=A[--i];
    		j--;
      	}
    	else if(Dir[i][j]=='|')
    		i--;
    	else
    		j--;
    }

    /*Uncomment next three lines,
    in case you want to see the LCS*/
    // for(i=c-1;i>=0;--i)
       	// printf("%c",LCSstring[i]);
    // printf("\n");

    /*Using the LCS, to get final ans*/
    i=m-1; j=n-1;
    int l=0,k=0; //used to make final array
    while(i>=0 || j>=0)
    {

    	if(l<countv)
    	{
       	/*Starting from last of B copy all elements
       	till its value doesnt match the last value
       	int the LCSstring*/

       	while(j>=0 && LCSstring[l]!=B[j])
    		{
       		ans[k++]=B[j--];
    		}

    		/*Starting from last of A copy all elements
       	till its value doesnt match the last value
       	int the LCSstring*/

      		while(i>=0 && LCSstring[l]!=A[i])
    		{
       		ans[k++]=A[i--];
    		}

    		/*Now both the last value of A and B
    		are equal to the last value of LCSstring*/

    		ans[k++]=LCSstring[l++];
    		j--;
    		i--;

       }
       else
       {
       	/*Now the LCSstring is drained, we just need
       	to add all the eleemnts that are left in B and then
       	in A. Order B then A is important*/

       	while(j>=0)
       		ans[k++]=B[j--];
       	while(i>=0)
       		ans[k++]=A[i--];
       }
    }
    /*We print the final answer*/
    for(i=k-1;i>=0;--i)
    	printf("%c",ans[i]);
    printf("\n");

}

int main() {
   char A[102],B[102];
   while(scanf("%s%s",A,B)!=EOF)
   {
      LCS(A,B,strlen(A),strlen(B));
   }
   return 0;
}
