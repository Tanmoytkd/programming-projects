/*input
5
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    
    if((k&1)==0) {
        cout << "NO" << endl;
        return 0;
    }

    int cnt=1;
    int mark[k+3];
    memset(mark, 0, sizeof mark);
    cout << "YES" << endl;

    if(k==1) {
    	cout << 2 << " " << 1 << endl;
    	cout << 1 << " " << 2 << endl;
    	return 0;
    }

    cout << 2*k+4 << " " << (2*k+4)*k/2 << endl;

    cout << k+2 << " " << 2*(k+2) << endl;
    int nodes=k+2;
    for(int i=1; i<nodes; i++) {
        for(int j=i+1; j<nodes; j++) {
            if(cnt<k && !mark[i] && !mark[j]) {
                cnt+=2;
                mark[i]=1;
                mark[j]=1;
                int fin=k+2;
                cout << i << " " << fin << endl;
                cout << i+nodes << " " << fin+nodes << endl;
                cout << j << " " << fin << endl;
                cout << j+nodes << " " << fin+nodes << endl;
            }
            else {
                cout << i << " " << j << endl;
                cout << i+nodes << " " << j+nodes << endl;
            }
        }
    }

    return 0;
}
