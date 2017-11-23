#include <bits/stdc++.h>

using namespace std;

int check(int n, int high) {
    int num, flag[n+1], res=1;

    for(int i=0; i<n; i++) flag[i]=0;
    flag[high]=1;
    high--;

    for(int i=1; i<n; i++) {
        scanf("%d", &num);
        flag[num]=1;

        if(num==high) {
            high--;
            while(flag[high]) high--;
        }
        else if(num>high) {
            high=num-1;
            while(flag[high]) high--;
        }
        else res=0;
    }
    return res;
}



int main() {

    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, num, start=1;
    while(scanf("%d", &n)==1  && n) {
        while(scanf("%d", &num)==1 && num) {
            int possible = check(n, num);
            if(possible) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
