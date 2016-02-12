#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prev2=0, prev1=1, fib=1, sum=0, lim;
    printf("Enter the upper limit of the sequence: ");
    scanf("%d", &lim);
    while((prev1+prev2)<=lim) {
        fib=prev1+prev2;
        if(fib%2==0) sum+=fib;
        printf("%d, ", fib);
        prev2=prev1;
        prev1=fib;
    }
    printf("\nSum = %d\n", sum);
    return 0;
}
