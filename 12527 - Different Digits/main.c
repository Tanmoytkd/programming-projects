#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    while(scanf("%d %d", &n, &m)==2) {
        int count=0;
        while(n<=m) {
            int i=n, j, digits[10], digit;
            for(j=0; j<10; j++) {
                digits[j]=0;
            }
            while(i) {
                int digit=i%10;
                if(digits[digit]==1) break;
                else digits[digit]=1;
                i/=10;
            }
            if(i==0) count++;
            n++;
        }
        printf("%d\n", count);
    }

    return 0;
}
