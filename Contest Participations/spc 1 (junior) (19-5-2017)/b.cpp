#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

int main() {
    ios::sync_with_stdio(false);
    lint t;
    cin >> t;

    while(t--) {
        vector<lint> v;
        lint negcnt=0;

        lint n;
        cin >> n;
        lint N=n;
        lint sum=0;
        while(n--) {
            lint num;
            cin >> num;
            sum+=num;
            v.push_back(0-num);
        }

        lint MX=0, s=0;
        for(lint i=0; i<N; i++) {
            if(v[i]<0) negcnt++;
            if(s+v[i]<0) s=0;
            else s+=v[i];

            MX=max(MX, s);

        }

        int allneg=1;
        for(int i=0; i<N; i++) {
            if(v[i]<0) allneg=0;
        }

        if(negcnt!=N) sum+=2*MX;
        else sum+=0;

        cout << sum << endl;
    }
    return 0;
}
