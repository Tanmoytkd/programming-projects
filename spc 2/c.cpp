#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int n;
    cin >> n;

    int cnt=0;

    while(n--) {
        long long int a, b, c;
        cin >> a >> b >> c;

        long long int s1=((a*x1+b*y1+c)>0);
        long long int s2=((a*x2+b*y2+c)>0);
        //cout << s1 << " " << s2 << endl;

        if((s1+s2)==1) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
