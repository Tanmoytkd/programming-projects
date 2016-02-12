#include <stdio.h>

int main()
{
    long long a, b, res;
    while(scanf("%lld %lld", &a, &b)!= EOF) {
        res = ((a-b)>=0) ? a-b : 0-(a-b);
        printf("%lld\n",  res);
    }
    return 0;
}
