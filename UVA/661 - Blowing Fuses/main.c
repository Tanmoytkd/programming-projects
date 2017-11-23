#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m, c, max, sequence=0, res=0, blown=0;
    while(scanf("%d %d %d", &n, &m, &c)==3) {
        sequence++;
        if(n==0 && m==0 && c==0) break;
        max=0, res=0, blown=0;

        int status[n], power[n], i;
        for(i=0; i<n; i++) {
            status[i]=0;
            scanf("%d", &power[i]);
        }

        for(i=0; i<m; i++) {
            int num;
            scanf("%d", &num);

            if(blown==0) {
                if(status[num-1]==0) {
                    status[num-1]=1;
                    res+=power[num-1];
                    if(res>c) blown=1;
                    else if(res>max) max=res;
                }
                else {
                    status[num-1]=0;
                    res-=power[num-1];
                }
            }
        }

        printf("Sequence %d\n", sequence);
        if(blown==1) printf("Fuse was blown.\n");
        else {
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", max);
        }
        printf("\n");
    }
    return 0;
}
