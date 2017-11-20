#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long p) {
    if(p==0) return 1;
    else if(p&1) return base*power(base, p-1);
    else {
        long long root = power(base, p/2);
        return root*root;
    }
}

void print(long long num) {
    string s="";
    while(num>0) {
        s+= '0'+(num%26);
        num/=26;
    }
    reverse(s.begin(), s.end());
    printf("%s\n", s.c_str());
}

int main() {
    vector<long long > v;
    v.push_back(1);
    int pos = 0;
    long long uplimit = LLONG_MAX / 26;


    while(pos<v.size()) {
        long long num = v[pos];
        if(num<=uplimit) {
            v.push_back(num*26);
            v.push_back(num*26+1);
        }
        pos++;
    }
//
//    for(int i=0; i<v.size(); i++) {
//        cout << v[i] << " ";
//        int cnt=0;
//        long long tmp=v[i];
//        while(tmp%2==0) {
//            cnt++;
//            tmp/=2;
//        }
//        cout << cnt << endl;
//        system("PAUSE");
//    }

    long long a, b, c, x, tst=0;
    while(scanf("%lld%lld%lld%lld", &a, &b, &c, &x)==4) {
        int possible=0;
        int startpos=upper_bound(v.begin(), v.end(), x)-v.begin();
        if(startpos==v.size()) {
            printf("Case %lld: No Solution\n", ++tst);
            continue;
        }

        a=power(2, a), b=power(3, b), c=power(5, c);

        for(int pos = startpos; pos<v.size(); pos++) {
            long long num = v[pos];
            if(num%a==0 && num%b==0 && num%c==0) {
                printf("Case %lld: ", ++tst);
                print(num);
                possible=1;
                break;
            }
        }

        if(!possible) {
            printf("Case %lld: No Solution\n", ++tst);
        }
    }

}
