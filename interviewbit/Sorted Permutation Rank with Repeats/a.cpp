string sorted;
long long mod = 1000003;
string s;
string chars;

int cnt[256];
long long in[1000007];
long long fct[1000007];
bool mark[1000007];


long long fact(long long n) {
    if (fct[n]!=0) {
        return fct[n];
    }
    
    if (n == 0) {
        fct[n] = 1%mod;
    } else {
        fct[n] = (n * fact(n-1))%mod;
    }
    
    return fct[n];
}

long long bigmod(long long base, long long p) {
    if (p == 0) return 1%mod;
    
    if (p % 2 == 1) return (base * bigmod(base, p-1))%mod;
    
    long long x = bigmod(base, p/2);
    return (x*x)%mod;
}


long long inv(long long val) {
    if (in[val]==0) {
        in[val] = bigmod(val, mod-2);
    }
    return in[val];
}



long long rec(int pos) {
    if (pos == s.size()) {
        return 1;
    }
    
    long long digleft = s.size() - pos;
    long long res = 0;
    for (int i = 0; i < sorted.size(); i++) {
        if (mark[i]) {
            continue;
        }
        
        if (sorted[i] != s[pos]) {
            if (i !=0 && !mark[i-1] && sorted[i] == sorted[i-1]) {
                continue;
            }
            char ch = sorted[i];
            long long addable = fact(digleft-1);
            for (char c : chars) {
                if (c != ch) {
                    addable *= inv(fact(cnt[c]));
                    addable %= mod;
                } else {
                    addable *= inv(fact(cnt[c]-1));
                    addable %= mod;
                }
            }
            res += addable;
            res %= mod;
        } else {
            mark[i] = true;
            cnt[s[pos]]--;
            res = ((res)%mod + rec(pos+1))%mod;
            break;
        }
        
    }
    return res;
}

int Solution::findRank(string A) {
    s = A;
    long long res = 0;
    
    memset(cnt, 0, sizeof cnt);
    
    for (char ch : A) {
        cnt[ch]++;
    }
    
    
    
    sorted = A;
    sort(sorted.begin(), sorted.end());
    memset(mark, 0, sizeof mark);
    
    if (chars == "") {
        for (char i = 'A'; i <= 'Z'; i++) {
            chars += i;
        }
        
        for (char i = 'a'; i <= 'z'; i++) {
            chars += i;
        }        
    }
    

    
    sort(chars.begin(), chars.end());
    // cout << chars << endl;
    // if (A == "bbbbaaaa") {
    //     for (char c: chars) {
    //         cout << c << " " << cnt[c] <<  "; ";
    //     }
        
    //     int i = 0;
    //     for (char c: s) {
    //         cout << c << " " << mark[i] <<  "; ";
    //         i++;
    //     }
    //     cout << "   ";
    // }
    
    return rec(0);
}
