#include <bits/stdc++.h>

using namespace std;

int dp[1<<20];

class RemovingParenthesis {
public:
	int countWays(string);
};

int isvalid(const string& s, int mask) {

    stack<char> stk;
    for(int i=0; i<s.size(); i++) {
        if((mask&(1<<i)) == 0) continue;
        if(s[i]==')' && !stk.empty() && stk.top()=='(') stk.pop();
        else stk.push(s[i]);
    }
    return stk.empty();
}

void debug(string s, int mask) {
    cout << s << endl;
    for(int i=0; i<s.size(); i++) {
       cout << ((mask>>i)&1);
    }
    cout << endl;

    for(int i=0; i<s.size(); i++) {
        if(mask&(1<<i)) {
            cout << s[i];
        }
    }
    cout << endl;
}

int calculate(string & s, int mask) {

//    debug(s, mask);
//    system("pause");
    int len=s.size();
    if(!isvalid(s, mask)) return 0;
    if(__builtin_popcount(mask)==0) return 0;
    if(__builtin_popcount(mask)==2) return 1;
    if(dp[mask]!=-1) return dp[mask];

    int & ret = dp[mask];
    ret=0;
    for(int spos=0; spos<len; spos++) {
        //cout << spos << " " << (mask>>spos)%2 <<endl;
        if((mask&(1<<spos)) == 0) continue;
        //if(i==1) system("pause");
        int newmask = mask & (~(1<<spos));

        for(int j=spos+1; j<len; j++) {
            if(s[j]==')' && ((newmask&(1<<j)))) {
                int finalmask = newmask & (~(1<<j));
                if(isvalid(s, finalmask)) {
                    //debug(s, finalmask);
                    ret+=calculate(s, finalmask);
                }
            }
        }
        break;
    }
    return dp[mask];

}

int RemovingParenthesis::countWays(string s) {
    int len=s.size();
    memset(dp, -1, sizeof dp);
    return calculate(s, (1<<len)-1);
}
