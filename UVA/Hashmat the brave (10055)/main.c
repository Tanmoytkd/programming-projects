#include <stdio.h>

int main()
{
    long long a, b, res;
    while(scanf("%lld %lld", &a, &b)!= EOF) {
        res = (a>b) ? a-b : b-a;
        printf("%lld\n",  res);
    }
    return 0;
}
