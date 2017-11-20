#include<stdio.h>

long long gcd(long long x, long long y){
	if(x<y) {
		long long temp=x;
		x=y;
		y=temp;
	}
    long long m=1;
    while (m!=0){
        m = x%y ;
        x = y;
        y = m;
    }
    return x;
}

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long S;
    scanf("%lld",&S);
    long long i, j, k, a, b, m, n, N, tcase=1;
    while (tcase <= S){

        scanf("%lld",&N);
        long long en[N];
        m = 1;
        n = 0;
        for(i=0 ; i<N ; i++){
            scanf("%lld", &en[i]);
            m *= en[i];

        }
        for(i=0 ; i<N ; i++){
            n += (m/en[i]);
        }
        m *= N;
        k = gcd(m,n);

        printf("Case %lld: %lld/%lld\n", tcase, m/k, n/k );

        tcase++;
    }
    return 0;
}
