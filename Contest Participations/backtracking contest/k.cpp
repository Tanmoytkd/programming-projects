#include <bits/stdc++.h>
using namespace std;

int possible;
int arr[10], visit[10];


void rec(int pos, int res) {
    if(pos==5) {
        //cout << res << endl;
        if(res==23) possible=1;
        return;
    }

    for(int i=0; i<5; i++) {
        if(visit[i]==0) {
            visit[i]=1;
            rec(pos+1, res+arr[i]);
            rec(pos+1, res-arr[i]);
            rec(pos+1, res*arr[i]);
            visit[i]=0;
        }
    }
}

int main() {
    while(scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4])==5) {
        int cnt=0;
        for(int i=0; i<5; i++) {
            //cout << arr[i] << endl;
            if(arr[i]==0) cnt++;
        }
        if(cnt==5) break;

        memset(visit, 0, sizeof visit);
        possible=0;

        for(int i=0; i<5; i++) {
            visit[i]=1;
            rec(1, arr[i]);
            visit[i]=0;
        }



        if(possible) puts("Possible");
        else puts("Impossible");

    }
    return 0;
}
