#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    while(x>-1) {
        if(x==0) printf("0\n");
        else {
            int rem, i=0, j, ternary[1000];
            while(x) {
                rem=x%3;
                ternary[i++]=rem;
                x/=3;
            }
            for(--i; i>=0; i--) printf("%d", ternary[i]);
            printf("\n");
        }
        scanf("%d", &x);
    }
    return 0;
}
