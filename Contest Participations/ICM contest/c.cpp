#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    int acnt, bcnt=-1, asum;
    for(asum=a, acnt=1; asum<=n; asum+=a, acnt++) {
        if((n-asum)%b == 0) {
            bcnt = (n-asum)/b;
            break;
        }
    }

//    cout << acnt << " " << bcnt << endl;

    if(bcnt==-1) {
        cout << -1 << endl;
        return 0;
    }

    int arr[n+1];

    int start=1;
    while(acnt--) {
        vector<int> v;
        for(int i=0; i<a; i++) {
            v.push_back(start+i);
        }


        for(int i=0; i<v.size(); i++) {
            int nxtpos = (i+1)%v.size();
            arr[v[i]]=v[nxtpos];
        }

        start+=a;
    }

    while(bcnt--) {
        vector<int> v;
        for(int i=0; i<b; i++) {
            v.push_back(start+i);
        }

        for(int i=0; i<v.size(); i++) {
            int nxtpos = (i+1)%v.size();
            arr[v[i]]=v[nxtpos];
        }

        start+=b;
    }

    if(a==1 || b==1) {
        for(int i=1; i<=n; i++) {
            arr[i]=i;
        }
    }

    for(int i=1; i<n; i++) printf("%d ", arr[i]);
    printf("%d\n", arr[n]);

    return 0;
}
