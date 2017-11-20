#include <bits/stdc++.h>
using namespace std;

int main() {
    //cout << 1 << endl;
    long long int row=1, col=1;
    int cnt=1;
    long long sum=1;
    while(1) {
        sum+=2*(row+col)+4;
        row++;
        col++;
        cnt++;
        if(sum>1e9) break;
        cout << sum << endl;
    }
    cout << cnt << endl;
}
