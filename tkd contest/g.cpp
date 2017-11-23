#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    int res=-1;
    if(d==0) res=0;
    else if(c==0) res=1;
    else if(b==0) res=0;
    else if(a==0) res=1;
    else if(f==0) res=0;
    else if(e==0) res=1;
    else if(b*d*f>a*c*e) res=1;
    else res=0;

    if(res) cout << "Ron" << endl;
    else cout << "Hermione" << endl;
}
