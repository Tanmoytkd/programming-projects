#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, product;
    for(i=1; i<999; i++) {
        for(j=i+1; j<999; j++) {
            int k=1000-(i+j);
            if(i*i+j*j==k*k) {
                product=i*j*k;
            }
        }
    }
    printf("%d\n", product);
    return 0;
}
