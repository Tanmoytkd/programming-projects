#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    unsigned int n, res;
    while(1) {
        scanf("%u", &n);
        if(n==0) break;

        res = sqrt(n);

        if(res*res==n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
