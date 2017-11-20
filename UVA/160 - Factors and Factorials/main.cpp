#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;
int arr[101], minfact[101];
int counter[101];

int main() {
    for(int i=2; i<101; i++) {
        if(arr[i]) continue;
        minfact[i]=i;
        for(int j=(i<<1); j<101; j+=i) {
            arr[j]=1;
            if(minfact[j]==0) minfact[j]=i;
        }
    }

    int num;
    while(sf1(num) && num) {
        memset(counter, 0, 101*sizeof(int));
        for(int i=2; i<=num; i++) {
            int n=i;
            while(n>1) {
                counter[minfact[n]]++;
                n/=minfact[n];
            }
        }

        pf("%3d! =", num);
        int pcount=0;
        for(int i=2; i<=num; i++) {
            if(arr[i]==0) {
                if(pcount==15) {
                    pf("\n      ");
                    pcount=0;
                }

                pf("%3d", counter[i]);
                pcount++;
            }
        }
        pf("\n");
    }

    return 0;
}
