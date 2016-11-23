#include<stdio.h>

int main()

{

     int testcase, i, x, y, z, sum;

     int caseno = 1;

     scanf("%d",&testcase);

     for(i = 1; i <= testcase; i++)

     {
        int mark;
        scanf("%d", &mark);
        printf("Case %d: ", i);
        if(mark>=80) puts("A+");
        else if(mark>=75) puts("A");
        else if(mark>=70) puts("A-");
        else if(mark>=65) puts("B+");
        else if(mark>=60) puts("B");
        else if(mark>=55) puts("B-");
        else if(mark>=50) puts("C");
        else if(mark>=45) puts("D");
        else puts("F");
     }

return 0;

}
