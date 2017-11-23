#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // TKD
    long long n;
    while(scanf("%lld", &n)==1) {
        long long prev, curr, count, jolly=1, diff, diffs[n], i;
        for(i=0; i<n; i++) {
            diffs[i]=0;
        }
        scanf("%lld", &prev);
        for(count=1; count<n; count++) {
            scanf("%lld", &curr);
            diff=abs(curr-prev);
            if(diff>=n || diff==0) {
                jolly=0;
            }
            else if(diffs[diff-1]==1){
                jolly=0;
            }
            else {
                diffs[diff-1]=1;
            }
            prev=curr;
        }
        switch(jolly) {
            case 0: printf("Not jolly\n"); break;
            case 1: printf("Jolly\n");
        }
    }
    return 0;
}
