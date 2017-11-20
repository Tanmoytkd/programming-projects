#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    while(scanf("%d %d", &i, &j) != EOF) {
        printf("%d %d ", i, j);
        if(i>j) {
            int temp=i;
            i=j;
            j=temp;
        }
        int max_cycle=0, cycle=0;
        while(i<=j) {
            cycle=1;
            unsigned int n=i;
            while(n!=1) {
                if(((n>>1)<<1)!=n) {
                    n=3*n+1;
                    n>>=1;
                    cycle+=2;
                }
                else {
                    n>>=1;
                    cycle++;
                }
            }
            if(cycle>max_cycle) {max_cycle=cycle;}
            i++;
        }
        printf("%d\n", max_cycle);
    }
    return 0;
}
