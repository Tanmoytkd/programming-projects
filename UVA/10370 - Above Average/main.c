#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int testcase, i;
    scanf("%d", &testcase);
    for(i=1; i<=testcase; i++) {
        int n, j;
        double avg=0, count=0;
        scanf("%d", &n);
        int marks[n];
        for(j=0; j<n; j++) {
            scanf("%d", &marks[j]);
            avg+=marks[j];
        }
        avg/=n;
        for(j=0; j<n; j++) {
            if(marks[j]>avg) count++;
        }

        double result=(count/n)*100;

        printf("%.3lf%%\n", result);
    }
    return 0;
}
