#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,x,y,c;
    cin >> n >> y >> x >> c;
    long long left=x-1, right=n-x, top=y-1, bottom=n-y;
    long long sum=1, t=0, width=1, height=1;
    while(sum<c) {
        t++;
        //sum+=2*(width+height)+4;

        if(left>0) sum+=height;
        if(right>0) sum+=height;
        if(top>0) sum+=width;
        if(bottom>0) sum+=width;
        if(left>0 && top>0) sum++;
        if(left>0 && bottom>0) sum++;
        if(right>0 && top>0) sum++;
        if(right>0 && bottom>0) sum++;


        if(left>0) {
            left--;
            width++;
        }
        if(right>0) {
            right--;
            width++;
        }
        if(top>0) {
            top--;
            height++;
        }
        if(bottom>0) {
            bottom--;
            height++;
        }
    }
    cout << t << endl;
    return 0;
}
