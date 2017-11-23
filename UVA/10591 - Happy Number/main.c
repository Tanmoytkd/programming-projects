#include <stdio.h>
#include <stdlib.h>

long long arrfind(long long arr[], long long count, long long key) {
    long long up=count-1, down=0, mid=(up+down)/2;
    while(down<=up) {
        mid=(up+down)/2;
        if(arr[mid]==key) return 1;
        else if(key < arr[mid]) up=mid-1;
        else down=mid+1;
    }
    if(arr[mid]==key) return 1;
    return 0;
}

long long sum(long long num) {
    long long s=0;
    while(num) {
        s+=(num%10)*(num%10);
        num/=10;
    }
    return s;
}


int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int testcase, i;
    scanf("%d", &testcase);
    for(i=1; i<=testcase; i++) {
        long long num, happy=0;
        scanf("%lld", &num);

        printf("Case #%d: %lld is ", i, num);

        long long arr[1000], pos=0;
        arr[pos]=num;
        pos++;

        num=sum(num);
        if(num==1) happy=1;
        while(arrfind(arr, pos, num)==0) {
            arr[pos]=num;
            pos++;
            num=sum(num);
            if(num==1) {
                happy=1;
                break;
            }
        }

        if(happy) printf("a Happy number.\n");
        else printf("an Unhappy number.\n");
    }

    return 0;
}
