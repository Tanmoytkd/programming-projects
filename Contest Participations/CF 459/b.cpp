#include <bits/stdc++.h>
using namespace std;
 int main() {
    int n, m;
    cin >> n >> m;

    map<string, string> name;

    for(int i=0; i<n; i++) {
        string x, y;
        cin >> x >> y;
        name[y]=x;
    }

    for(int i=0; i<m; i++) {
        string command, ip;
        cin >> command >> ip;
        cout << command << " " << ip << " #" << name[ip.substr(0, ip.length()-1)] << endl;
    }
    return 0;
 }
