#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test, cases=0;
    scanf("%d", &test);
    while(test!=0) {
        cases++;
        double u, v, t, a, s;
        if(test==1) {
            scanf("%lf %lf %lf", &u, &v, &t);
            a=(v-u)/t;
            s=u*t + a*t*t/2;
            printf("Case %d: %.3lf %.3lf\n", cases, s, a);
        }
        else if(test==2) {
            scanf("%lf %lf %lf", &u, &v, &a);
            t= (v-u)/a;
            s=u*t + a*t*t/2;
            printf("Case %d: %.3lf %.3lf\n", cases, s, t);
        }
        else if(test==3) {
            scanf("%lf %lf %lf", &u, &a, &s);
            int v2= u*u + 2*a*s;
            v= (v2>=0) ? sqrt(v2) : 0-sqrt(0-v2);
            t=(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n", cases, v, t);
        }
        else if(test==4) {
            scanf("%lf %lf %lf", &v, &a, &s);
            int u2=v*v - 2*a*s;
            u= (u2>=0) ? sqrt(u2) : 0-sqrt(0-u2);
            t=(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n", cases, u, t);
        }
        scanf("%d", &test);
    }
    return 0;
}
