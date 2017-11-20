#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        int num;
        scanf("%d", &num);

        num = (num*63+7492)*5-498;
        num = abs(num%100)/10;
        printf("%d\n", num);
    }
    return 0;
}
