string sorted;
bool mark[1000007];
long long mod = 1000003;
string s;

long long fct[1000007];
long long fact(int n) {
    if (fct[n]!=0) {
        return fct[n];
    }
    
    if (n == 0) {
        fct[n] = 1;
    } else {
        fct[n] = (n * fact(n-1))%mod;
    }
    
    return fct[n];
}

long long rec(int pos) {
    if (pos == s.size()) {
        return 1;
    }
    
    long long digleft = s.size() - pos;
    long long res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (mark[i]) {
            continue;
        }
        
        if (sorted[i] != s[pos]) {
            res += fact(digleft-1);
            res %= mod;
        } else {
            mark[i] = true;
            res = ((res)%mod + rec(pos+1))%mod;
            break;
        }
        
    }
    return res;
}

int Solution::findRank(string A) {
    s = A;
    long long res = 0;
    
    sorted = A;
    sort(sorted.begin(), sorted.end());
    memset(mark, 0, sizeof mark);
    
    return rec(0);
}
