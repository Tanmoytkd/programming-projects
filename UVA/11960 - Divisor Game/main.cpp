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
struct num {
    int div;
    int basediv;
    int prime;
    int imax;

    num() {
        div=-1;
        basediv=-1;
        prime=-1;
        imax=-1;
    }
} arr[1000001];

int main() {

    for(int i=0; i<=2; i++) {
        arr[i].div=i;
        arr[i].basediv=i;
        arr[i].prime=i;
        arr[i].imax=i;
    }

    int tempu=2;
    for(int x=2; tempu<1000001; tempu*=2, x++) {
                arr[tempu].div=x;
                arr[tempu].basediv=x;
                arr[tempu].prime=2;
    }



    for(int i=3; i<=1000; i+=2) {
        if(arr[i].prime==-1) {
            int temp=i;
            for(int x=2; temp<1000001; temp*=i, x++) {
                arr[temp].div=x;
                arr[temp].basediv=x;
                arr[temp].prime=i;
            }
            for(int j=i+i; j<1000001; j+=i) {
                if(arr[j].prime==-1) {
                    arr[j].prime=i;
                }
            }
        }
    }

    //cout << "TKD" << endl;

    for(int i=3; i<1000001; i++) {
        if(i&1==0) arr[i].prime=2;
        if(arr[i].prime==-1) {
            arr[i].div=2;
            arr[i].basediv=2;
            arr[i].prime=i;
        }

        //cout << i << endl;

        if(arr[i].div==-1) {
            int prime=arr[i].prime, pos=i/prime;
            int div, basediv;
            if(prime==arr[pos].prime) {
                div=arr[pos].div+arr[pos].basediv;
                basediv=arr[pos].basediv;
            }
            else {
                div=arr[pos].div+arr[pos].div;
                basediv=arr[pos].div;
            }
            arr[i].div=div;
            arr[i].basediv=basediv;
        }

        arr[i].imax = (arr[i].div>=arr[arr[i-1].imax].div) ? i: arr[i-1].imax;
    }

    int t, n;
    sf1(t);
    while(t--) {
        sf1(n);
        pf1(arr[n].imax);
    }

    return 0;
}
