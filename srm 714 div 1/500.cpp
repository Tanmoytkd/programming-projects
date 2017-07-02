#include <bits/stdc++.h>
using namespace std;

long long K;
map<long long, long long> dp;
map<long long, map<long long , long long> > mem;

long long calculateg(long long n) {
    //ct++;
    if(dp.count(n)!=0) return dp[n];
    long long cnt=0;
    while(n>K) {
        //ct++;
        if(n&1) {
            n+=K;
        }
        else {
            n/=2;
        }
        cnt++;
    }
    dp[n]=cnt;
    return cnt;
}

long long rec(long long l, long long r) {
    //ct+=2;
    //cout << l << " " << r << endl;
    if(r<=K) return 0;
    if(l<=K) {
        l=K+1;
    }
    if(l==r) return calculateg(l);
    if(mem[l].count(r)==0) {
        long long minodd, mineven, maxodd, maxeven, oddcount, evencount;
        if(l&1) {
            minodd=l;
            mineven=l+1;
        }
        else {
            mineven=l;
            minodd=l+1;
        }
        if(r&1) {
            maxodd=r;
            maxeven=r-1;
        }
        else {
            maxeven=r;
            maxodd=r-1;
        }
        oddcount = (maxodd-minodd)/2+1;
        evencount = (maxeven-mineven)/2+1;

        long long res = 0;
        res+= 2*oddcount + rec((minodd+K)/2, (maxodd+K)/2);
        res+= evencount + rec(mineven/2, maxeven/2);

        mem[l][r]=res;
    }
    return mem[l][r];
    //return res;
}

class NAddOdd {
public:
	long long solve(long long, long long, int);
};

long long NAddOdd::solve(long long L, long long R, int k) {
    K=k;
    return rec(L, R);
}

#ifdef TKD
int main() {
    long long l, r, k;

    cin >> l >> r >> k;

    NAddOdd d;
    cout << d.solve(l,r,k) << endl;
    //cout << ct << endl;
}
#endif
