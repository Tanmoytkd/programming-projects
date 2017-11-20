#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // TKD
    int n;
    while(scanf("%d", &n)!=EOF) {
        int arr[n], i, j, k, count=0, key;
        for(i=0; i<n; i++) {
            scanf("%d", &arr[i]);
        }
        for(j=1; j<n; j++) {
            k=j;
            while(k!=0 && arr[k]<arr[k-1]) {
                key=arr[k];
                arr[k]=arr[k-1];
                arr[k-1]=key;
                k--;
                count++;
            }
        }
        printf("Minimum exchange operations : %d\n", count);
    }
    return 0;
}
