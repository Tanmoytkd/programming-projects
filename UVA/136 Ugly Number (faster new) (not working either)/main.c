#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long arr[1600], i, pos=1;
    arr[0]= 1;
    printf("%lld: %lld\n",pos, arr[pos-1]);
    for(i=0; pos<1597; i++) {
        arr[pos++]=arr[i]*2;
        getch();
        printf("%lld: %lld\n",pos, arr[pos-1]);
        arr[pos++]=arr[i]*3;
        getch();
        printf("%lld: %lld\n",pos, arr[pos-1]);
        arr[pos++]=arr[i]*5;
        getch();
        printf("%lld: %lld\n",pos, arr[pos-1]);
    }

    for(i=0; i<1600; i++) {
        printf("%lld\n", arr[i]);
    }
    return 0;
}
