#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test=0;
    scanf("%d", &test);
    int i;
    for(i=1; i<=test; i++) {
        int t1, t2, fin, att, ct1, ct2, ct3, ct;
        scanf("%d %d %d %d %d %d %d", &t1, &t2, &fin, &att, &ct1, &ct2, &ct3);

        ct=ct1+ct2+ct3;
        int smallest=ct1;
        if(ct2<smallest) smallest=ct2;
        if(ct3<smallest) smallest=ct3;
        ct-=smallest;
        ct/=2;

        int result= t1+t2+fin+att+ct;
        result/=10;

        printf("Case %d: ", i);
        switch(result) {
            case 10:
            case 9: printf("A\n"); break;
            case 8: printf("B\n"); break;
            case 7: printf("C\n"); break;
            case 6: printf("D\n"); break;
            default: printf("F\n"); break;
        }
    }
    return 0;
}
