#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    char str[n+1];

    for(int i=0; i<n; i++) {
        str[i]='o';
    }
    str[n]='\0';

    int a=1, b=1, c=0;

    str[a-1]='O';

    //cout << n << endl;

    while(1) {
        c=a+b;
        if(c>n) break;
        a=b;
        b=c;
        str[c-1]='O';


        //cout << c << endl;
    }

    cout << str << endl;
}
