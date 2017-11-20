#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testcase;
    scanf("%d", &testcase);

    int i, a, b;
    for(i=1; i<=testcase; i++) {
        scanf("%d %d", &a, &b);

        if(a<b) printf("<\n");
        else if(a>b) printf(">\n");
        else printf("=\n");
    }

    return 0;
}
