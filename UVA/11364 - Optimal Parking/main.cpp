#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int testcase;
    scanf("%d", &testcase);

    for(int i=0; i<testcase; i++) {
        int num, imin=100, imax=-1, n, dist;
        scanf("%d", &num);

        for(int j=0; j<num; j++) {
            scanf("%d", &n);
            if(n<imin) imin=n;
            if(n>imax) imax=n;
        }
        dist=(imax-imin)*2;
        printf("%d\n", dist);
    }
    return 0;
}
