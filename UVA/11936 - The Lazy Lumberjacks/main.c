#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, i, a, b, c;
    scanf("%d", &n);

    for(i=1; i<=n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(a+b>c && b+c>a) printf("OK\n");
        else printf("Wrong!!\n");
    }

    return 0;
}
