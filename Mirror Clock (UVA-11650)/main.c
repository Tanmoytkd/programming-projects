#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test=0, i;
    scanf("%d", &test);

    for(i=1; i<=test; i++) {
        int h, m;
        scanf("%d:%d", &h, &m);
        if(m==0) {
            h = (h==12) ? 12:(12-h);
        }
        else {
            m = (60-m);
            h=(11-h);
            h=(h>0) ? h:(12+h);
        }
        if(h<10) {
            printf("0%d:", h);
        }
        else {
            printf("%d:", h);
        }
        if(m<10) {
            printf("0%d\n", m);
        }
        else {
            printf("%d\n", m);
        }
    }
    return 0;
}
