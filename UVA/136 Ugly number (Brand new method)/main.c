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

long long insert(long long arr[], long long count, long long key) {
    arr[count]=key;
    long long i=count;
    while(i!=0 && arr[i]<arr[i-1]) {
        arr[i]=arr[i-1];
        arr[i-1]=key;
        i--;
    }
    return i;
}

int main()
{
    long long lim=1500, extra=100;
    /*scanf("%lld", &lim);
    scanf("%lld", &extra);*/
    long long arr[lim+extra], count=0, i, pos;
    arr[0]=1;
    count++;

    for(i=0; count<lim+extra; i++) {
        int m, multi;
        for(m=1; m<=3; m++) {
            switch(m) {
                case 1: multi=2; break;
                case 2: multi=3; break;
                case 3: multi=5; break;
            }

            long long key=arr[i]*multi;
            if(arrfind(arr, count, key)==0) {
                pos=insert(arr, count, key);
                count++;
            }
            if(count==lim+extra) break;
        }
    }

    printf("The 1500'th ugly number is %lld.\n", arr[lim-1]);
    return 0;
}
