#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int h, m;
    while(scanf("%d:%d", &h, &m)==2) {

        if(h==0 && m==0) break;

        double mdeg=m*6, hdeg=h*5*6 + (double) m/2, res;
        res=hdeg-mdeg;
        if(res<0) res+=360;
        else if(res>180) res=360-res;

        if(res>180) res=360-res;
        printf("%.3lf\n", res);
    }
    return 0;
}
