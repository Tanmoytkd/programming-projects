#include <stdio.h>
#include <stdlib.h>

int is_prime(int x) {
    if (x==1) return 0;
    else if(x==2) return 1;
    else if((x&1)==0) return 0;
    else {
        int i;
        for(i=3; i*i<=x; i+=2) {
            if(x%i==0) return 0;
        }
        return 1;
    }
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF) {
        if(is_prime(n)==0) printf("%d is not prime.\n", n);
        else {
            int rev=0, temp=n;
            while(temp>0) {
                rev = rev*10 + temp%10;
                temp/=10;
            }

            if(rev!=n && is_prime(rev)==1) printf("%d is emirp.\n", n);
            else printf("%d is prime.\n", n);
        }
    }
    return 0;
}
