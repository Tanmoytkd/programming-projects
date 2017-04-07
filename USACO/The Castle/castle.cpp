#include <bits/stdc++.h>
using namespace std;

int data[55][55];
int r, c;
int fx[4] = {-1, 0, 1, 0}, fy[4] = {0, -1, 0, 1};

int exist(int flag, int dir) {
	if(flag&(1<<dir)) return 1;
	return 0;
}

int main() {
    cin >> c >> r;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            cin >> data[i][j];
        }
    }

    int comp=0;


    return 0;
}
