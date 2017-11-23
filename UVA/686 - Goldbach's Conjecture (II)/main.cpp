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
int arr[33000];

int main() {
    for(int i=2; i<185; i++) {
        if(arr[i]) continue;
        for(int j=i+i; j<33000; j+=i) arr[j]=1;
    }

    int num;
    while(sf("%d", &num) && num) {
        int counter=0;
        for(int i=2; (i<<1)<=num; i++)
            if(!arr[i] && !arr[num-i]) counter++;

        pf1(counter);
    }

    return 0;
}
