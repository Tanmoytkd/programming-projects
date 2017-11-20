#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    unsigned int a, b;
    while(scanf("%u %u", &a, &b)==2) {
        unsigned int result = a^b;
        printf("%u\n", result);
    }
    return 0;
}
