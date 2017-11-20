#include <stdio.h>
#include <limits.h>

int distance(int street[], int n, int avg) {
    int i=0, dis=0;
    for(i=0; i<n; i++) {
        dis+= abs(avg-street[i]);
    }
    return dis;
}

int main() {

    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int testcase, i;
    scanf("%d", &testcase);

    for(i=1; i<=testcase; i++) {
        int members, j;
        scanf("%d", &members);
        int street[members], avg=0;
        for(j=0; j<members; j++) {
            scanf("%d", &street[j]);
            avg+=street[j];
        }

        avg/=members;

        while(distance(street, members, avg)>=distance(street, members, avg+1)) avg++;
        while(distance(street, members, avg)>=distance(street, members, avg-1)) avg--;

        printf("%d\n", distance(street, members, avg));
    }

    return 0;
}
