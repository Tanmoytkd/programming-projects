#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d", &test);
    int i;
    for(i=1; i<=test; i++) {
        int n, j, k, count=0;;
        scanf("%d", &n);
        int arr[n];
        for(j=0; j<n; j++) {
            scanf("%d", &arr[j]);
        }

        for(j=1; j<n; j++) {
            k=j;
            while(k!=0 && arr[k]<arr[k-1]) {
                int key=arr[k];
                arr[k]=arr[k-1];
                arr[k-1]=key;
                k--;
                count++;
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    return 0;
}
