#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, res, testcase;
    scanf("%d", &testcase);

    while(testcase--) {
        scanf("%d", &n);
        res=sqrt(n);

        if(res*res==n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
