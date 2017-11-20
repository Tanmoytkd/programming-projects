#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int testcase=0;
    char str[1000001];

    while(scanf("%s", str)!=EOF) {
        testcase++;
        int len= strlen(str);
        if(len==0) break;
        printf("Case %d:\n", testcase);
        int test, i;
        scanf("%d", &test);
        for(i=1; i<=test; i++) {
            int low, high, same=1;
            scanf("%d %d", &low, &high);
            if(low>high) {
                int x=low;
                low=high;
                high=x;
            }

            if(low<0 || high>=len) same=0;
            else {
                int j=low;
                char ch=str[j];
                j++;
                for(; j<=high; j++) {
                    if(str[j]!=ch) {
                        same=0;
                        break;
                    }
                }
            }

            if(same==1) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}
