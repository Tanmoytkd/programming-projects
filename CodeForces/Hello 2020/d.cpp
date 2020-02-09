#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, vector<int> > a, b;

    for(int i=1; i<=n; i++) {
        int sa, ea, sb, eb;
        cin >> sa >> ea >> sb >> eb;

        a[sa].push_back(i);
        a[ea].push_back(i);

        b[sb].push_back(i);
        b[eb].push_back(i);
    }

    vector<int> a1, b1;

    for(auto it=a.begin(); it!=a.end(); it++) {
        sort(it->second.begin(), it->second.end());

        for(auto x: it->second) {
            a1.push_back(x);
        }
    }

    for(auto it=b.begin(); it!=b.end(); it++) {
        sort(it->second.begin(), it->second.end());

        for(auto x: it->second) {
            b1.push_back(x);
        }
    }

    bool match = true;

    for(int i=0; i<a1.size(); i++) {
        match = match && (a1[i]==b1[i]);
    }

    cout << ((match) ? "YES":"NO") << endl;
    return 0;
}
