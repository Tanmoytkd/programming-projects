#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int64_t sum=0;
    int lim, i, j;
    scanf("%d", &lim);
    char arr[lim];
    //printf("Done it\n");

    for(i=0; i<lim; i++) {
        arr[i]=1;
        //printf("Done it\n");
    }


    for(i=2; i<=lim; i++) {
        if(arr[i-1]==1) {
            sum+=i;
            //printf("%"PRId64"\n", sum);
            for(j=i+i; j<=lim; j+=i) {
                arr[j-1]=0;
            }
        }
    }
    printf("%"PRId64"", sum);

    return 0;
}
