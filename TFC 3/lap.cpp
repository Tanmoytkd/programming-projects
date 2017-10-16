#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    while(scanf("%d %d",&x,&y)==2){
        int xdist = 0 , ydist = 0;
        int lap = 1 ;
        while(1){
            if( (ydist-xdist) >= x ) break;
            lap++;
            xdist += x , ydist += y ;
        }
        printf("%d\n",lap);
    }
    return 0;
}