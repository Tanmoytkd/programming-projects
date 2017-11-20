#include <stdio.h>
#include <stdlib.h>

int calc(unsigned int n) {
	if(n==1) return 1;

    if(n&1) {
        n=3*n+1;
        n>>=1;
        return 2+calc(n);
    }
    else {
        n>>=1;
        return 1+ calc(n);
    }
}

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
            cycle=calc(n);
            if(cycle>max_cycle) {max_cycle=cycle;}
            i++;
        }
        printf("%d\n", max_cycle);
    }
    return 0;
}
