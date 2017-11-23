#include <bits/stdc++.h>
using namespace std;
#define MX 1000007
int a[MX], b[MX], p1[MX], p2[MX], tst;

int comp1(int i, int j) {
    return a[i]>a[j];
}

int comp2(int i, int j) {
    return b[i]>b[j];
}

void solve(int n) {
    for(int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        a[i]=num;
        p1[i]=i;
    }

    for(int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        b[i]=num;
        p2[i]=i;
    }

    sort(p1, p1+n, comp1);
    sort(p2, p2+n, comp2);

//    for(int i=0; i<n; i++) {
//        cout << p1[i] << " " << p2[i] << endl;
//    }

    for(int i=0; i<n; i++) {
        if(p1[i]!=p2[i]) {
            printf("Case %d: %d\n", ++tst, i+1);
            return;
        }
    }
    printf("Case %d: agree\n", ++tst);
}

int main() {
    int n;
    while(scanf("%d", &n)==1) {
        solve(n);
    }

    return 0;
}
