#include <bits/stdc++.h>
using namespace std;

string a, b;
int alreadyFound = 0;
int cnt[256];
vector<char> result;

void rec(int digit, int alreadySmaller) {
    if(alreadyFound) return;
    if(digit==b.size()) {
        for(int i=0; i<result.size(); i++) cout << result[i];
        cout << endl;
        alreadyFound = 1;
        return;
    }

    char currentDigit;
    if(alreadySmaller) currentDigit='9';
    else currentDigit = b[digit];
    for(; currentDigit>='0'; currentDigit--) {
        if(cnt[currentDigit]) {
            result.push_back(currentDigit);
            cnt[currentDigit]--;

            rec(digit+1, currentDigit<b[digit] || alreadySmaller);

            cnt[currentDigit]++;
            result.pop_back();
        }
    }
}


int main() {
    cin >> a >> b;

    if(a.size()<b.size()) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        cout << a << endl;
    } else {
        memset(cnt, 0, sizeof cnt);
        for(int i=0; i<a.size(); i++) {
            char ch = a[i];
            cnt[ch]++;
        }

        rec(0, 0);
    }
    return 0;
}
