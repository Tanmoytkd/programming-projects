#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long n;
    while(1) {
        scanf("%lld", &n);
        if(n==0) break;

        long long row, col;

        row=sqrt(n);
        col=row;

        n-=row*row;

        if(n==0) {
            if(row&1) printf("1 %lld\n", row);
            else printf("%lld 1\n", col);
            continue;
        }

        row++;
        col++;

        if(row&1) {
            if(n<row) row=n;
            else if(n>col) col-=(n-col);
        }
        else {
            if(n<col) col=n;
            else if(n>row) row-=(n-row);
        }

        printf("%lld %lld\n", col, row);
    }
    return 0;
}
