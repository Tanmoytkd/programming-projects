#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n;
    while(1) {
        scanf("%u", &n);
        if(n==0) break;
        int status=1, i;

        while(1) {
            while(n%2==0) {
                n/=2;
                status=(status==0) ? 1:0;
            }
            for(i=3; i<=n; i+=2) {
                while(n%i==0) {
                    n/=i;
                    status= (status==0) ? 1:0;
                }
            }
            if(n==1) break;
        }
        if(status==1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
