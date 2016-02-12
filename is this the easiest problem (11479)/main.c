#include <stdio.h>


int main()
{
    long long test=1, i, a, b, c;
    scanf("%lld", &test);
    for(i=1; i<=test; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if((a+b)<=c || (b+c)<=a || (c+a)<=b || a<=0 || b<=0 || c<=0) printf("Case %lld: Invalid\n", i);
        else {
            if(a==b && b==c) printf("Case %lld: Equilateral\n", i);
            else if(a==b || b==c || c==a) printf("Case %lld: Isosceles\n", i);
            else printf("Case %lld: Scalene\n", i);
        }
    }
    return 0;
}
