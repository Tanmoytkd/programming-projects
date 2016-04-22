#include <iostream>
#include <conio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef TKD
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int testcase;
    cin >> testcase;

    string blank;
    getline(cin, blank);

    for(int i=1; i<=testcase; i++) {
        string s;
        cin >> s;
        int len = s.length();


        for(int j=1; j<len; j++) {
            char first=s[0];
            int x=j;
            while(s[x]>=first && x!=0) {
                swap(s[x], s[x-1]);
                x--;
            }
        }

        cout << "Case #" << i << ": " << s << endl;
    }

    return 0;
}
