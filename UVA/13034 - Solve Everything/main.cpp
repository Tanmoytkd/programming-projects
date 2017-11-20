#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int main() {
    int s;
    cin >> s;
    for(int i=1; i<=s; i++) {
        int res=1, num;
        for(int j=0; j<13; j++) {
            cin >> num;
            res &= num>0;
        }
        cout << "Set #" << i << ": ";
        if(res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
