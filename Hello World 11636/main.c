#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test=1, n;
    scanf("%d", &n);
    while(n>=0) {
        int counter=0, curr=1;
        while(curr<n) {
            if((n-curr)>=curr) curr*=2;
            else curr+=n-curr;

            counter++;
        }

        printf("Case %d: %d\n", test, counter);
        test++;
        scanf("%d", &n);
    }
    return 0;
}
