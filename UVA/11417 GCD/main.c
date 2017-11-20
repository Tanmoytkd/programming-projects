#include <stdio.h>
#include <stdlib.h>

int gcd(int i, int j) {
    int l= (i>j) ? i:j;
    int s= (i>j) ? j:i;
    int rem;
    while(s!=0) {
        rem=l%s;
        l=s;
        s=rem;
    }
    return l;
}

int main()
{
    int n, i, j;
    scanf("%d", &n);
    while(n!=0) {
        int g=0;
        for(i=1; i<n; i++) {
            for(j=i+1; j<=n; j++) {
                g+= gcd(i,j);
            }
        }
        printf("%d\n", g);
        scanf("%d", &n);
    }
    return 0;
}
