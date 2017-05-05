#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long t;
    cin >> t;

    while(t--) {
        vector<long long> v;
        long long negcnt=0;

        long long n;
        cin >> n;
        long long N=n;
        long long sum=0;
        while(n--) {
            long long num;
            cin >> num;
            sum+=num;
            v.push_back(0-num);
        }

        long long mx=0, s=0;
        for(long long i=0; i<N; i++) {
            if(v[i]<0) negcnt++;
            if(s+v[i]<0) s=0;
            else s+=v[i];

            mx=max(mx, s);

        }

        if(negcnt!=N) sum+=2*mx;

        cout << sum << endl;
    }
    return 0;
}
