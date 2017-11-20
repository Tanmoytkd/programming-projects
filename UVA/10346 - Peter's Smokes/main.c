#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    while(scanf("%d %d", &n, &k)==2) {
        int sum=n;
        while(n>=k) {
            sum+=n/k;
            n=n%k+n/k;
        }
        printf("%d\n", sum);
    }
    return 0;
}
