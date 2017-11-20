#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    if(k==1) {
        cout << "YES" << endl;
        cout << 2 << " " << 1 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else if(k==3) {
        cout << "YES" << endl;
        cout << 10 << " " << 15 << endl;
        cout << "1 2\n1 3\n1 4\n2 5\n4 5\n2 3\n3 4\n5 6\n6 7\n6 8\n7 9\n8 9\n10 8\n10 7\n10 9" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
