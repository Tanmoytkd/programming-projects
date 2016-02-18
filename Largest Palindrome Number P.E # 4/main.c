#include <stdio.h>
#include <stdlib.h>

int ispalin(int x) {
    int i;
    if(x<100000) {
        int data[5];
        for(i=4; i>=0; i--) {
            data[i] = x%10;
            x/=10;
        }
        if(data[0]==data[4] && data[1]==data[3]) return 1;
        else return 0;
    }
    else {
        int data[6];
        for(i=5; i>=0; i--) {
            data[i]=x%10;
            x/=10;
        }
        if(data[0]==data[5] && data[1]==data[4] && data[2]==data[3]) return 1;
        else return 0;
    }
}

int main()
{
    int i, j, res, max=0;
    for(i=100; i<1000; i++) {
        for(j=100; j<1000; j++) {
            res = i*j;
            if(ispalin(res)==1 && res>max) {
                max = res;
                printf("%d*%d %d\n", i, j, max);
            }
        }
    }
    printf("\nMax Palindrome number = %d\n", max);
    return 0;
}
