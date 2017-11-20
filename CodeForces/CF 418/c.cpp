#include <bits/stdc++.h>
using namespace std;

int dp[1507][255], cum[255][1507];
string s;

int rangesum(int * arr, int start, int fin) {
    if(start==0) return arr[fin];
    return arr[fin]-arr[start-1];
}

int main() {
    int len;
    cin >> len;

    cin >> s;
    for(int i=0; i<len; i++) {
        int letter = s[i]-'a';
        cum[letter][i]++;
    }
    for(int i=1; i<len; i++) {
        for(int ch=0; ch<26; ch++) {
            cum[ch][i]+=cum[ch][i-1];
        }
    }

    for(int i=0; i<len; i++) {
        for(int j=i; j<len; j++) {
            for(int ch=0; ch<26; ch++) {
                int cost = (j-i+1)-rangesum(cum[ch], i, j);
                dp[cost][ch] = max(dp[cost][ch], j-i+1);
            }
        }
    }

    for(int i=1; i<=len; i++) {
        for(int ch=0; ch<26; ch++) {
            dp[i][ch]=max(dp[i][ch], dp[i-1][ch]);
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int cost;
        char ch;
        cin >> cost >> ch;
        while(ch==' ') cin >> ch;

        int letter = ch-'a';

        cout << dp[cost][letter] << endl;
    }
    return 0;
}
