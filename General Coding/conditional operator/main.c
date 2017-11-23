#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, i, test=0;
    scanf("%d", &test);
    for(i=0; i<test; i++) {
        scanf("%d %d", &a, &b);
        char res;
        res = (a==b) ? '=' : ((a>b) ? '>' : '<');
        printf("%c\n", res);
    }
    return 0;
}
