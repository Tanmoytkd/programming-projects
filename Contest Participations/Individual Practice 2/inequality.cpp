#include<bits/stdc++.h>
using namespace std;

long long common (long long a, long long b) {
	if(a>b) return 0;
	return (b-a)+1;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
    	long long res=0;
        long long a,b,c,d;
        
        cin >> a >> b >> c >> d;

        if(a>b) swap(a,b);
        if(c>d) swap(c,d);

        for(long long i=a; i<=b; i++) {
            if(i<d) {
                long long start=max(c,i+1);
                res+=common(start, d);
            }
        }

        cout<<res<<endl;
    }
    return 0;
}
