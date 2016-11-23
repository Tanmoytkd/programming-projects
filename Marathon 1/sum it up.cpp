#include<stdio.h>

int main()

{

     int testcase, i, x, y, z, sum;

     int caseno = 1;

     scanf("%d",&testcase);

     for(i = 1; i <= testcase; i++)

     {

          scanf("%d %d %d", &x, &y, &z);
          int sum=x+y+z;

          //write lines to keep the sum of x, y and z in sum variable

          printf("Case %d: ", caseno);

          caseno++;

          printf("Sum of %d, %d and %d is %d", x, y, z, sum);
          printf("\n");

     }

return 0;

}
