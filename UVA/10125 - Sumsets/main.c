#include <stdio.h>
#include <stdlib.h>

int compare_function(const void *a,const void *b) {
int *x = (int *) a;
int *y = (int *) b;
return *x - *y;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    while(n!=0) {
        long long i, a, b, c, d, max=0, no_sol=1;
        long long arr[n];
        for(i=0; i<n; i++) {
            scanf("%lld", &arr[i]);
        }

        //sort(arr, arr+n);
        qsort(arr,n,sizeof(*arr),compare_function);

        /*for(a=0; a<=(n-3); a++) {
            for(b=a+1; b<=(n-2); b++) {
                for(c=b+1; c<=(n-1); c++) {
                    for(d=(n-1); d>=0; d--) {
                        if(d!=a && d!=b && d!=c && arr[a]+arr[b]+arr[c]==arr[d]) {
                            if(no_sol==1) {
                                max=arr[d];
                                no_sol=0;
                            }
                            else {
                                if(arr[d]>max) max=arr[d];
                            }
                        }
                    }
                }
            }
        }*/

        for(d=n-1; d>=3; d--) {
            for(c=d-1; c>=2; c--) {
                for(b=c-1; b>=1; b--) {
                    for(a=b-1; a>=0; a--) {
                        if(arr[d]==arr[c]+arr[b]+arr[a]) {
                            if(no_sol==1) {
                                no_sol=0;
                                max=arr[d];
                            }
                            else {
                                if(arr[d]>max) max=arr[d];
                            }
                        }
                    }
                }
            }
        }

        if(no_sol==1) printf("no solution\n");
        else printf("%lld\n", max);

        scanf("%d", &n);
    }
    return 0;
}
