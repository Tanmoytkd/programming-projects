#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    long long mod[32], i, b, p, m, res=1;

    while(scanf("%lld %lld %lld", &b, &p, &m)==3) {
        if(m==1 || b==0) {
            printf("0\n");
            continue;
        }
        else if(p==0) {
            printf("1\n");
            continue;
        }
        else {
            i=0;
            res=1;
            long long power=p;

            mod[i]=b%m;
            if((power&1)==1) res=(res*mod[i])%m;
            power>>=1;
            i++;

            while(power>0) {
                mod[i]=(mod[i-1]*mod[i-1])%m;
                if((power&1)==1) res=(res*mod[i])%m;
                power>>=1;
                i++;
            }

            printf("%lld\n", res);
        }
    }
    return 0;
}
