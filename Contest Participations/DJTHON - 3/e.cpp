#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long res=0;
    int len=s.length();
    for(char ch='a'; ch<='z'; ch++)
    {
        long long add=0;
        for(int i=0; i<len; i++) {
            if(s[i]!=ch) add++;
        }
        add++;
        res+=add;
    }
    cout << res << endl;
}
