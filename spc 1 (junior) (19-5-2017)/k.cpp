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

struct city {
    int pos;
    int dist;
};

bool comp(city a, city b) {
    return  a.dist<b.dist;
}

int main() {

    int n;
    sf1(n);
    city arr[n];
    for(int i=0; i<n; i++) {
        int dist;
        sf1(dist);
        arr[i].pos=i+1;
        arr[i].dist=dist;
    }
    sort(arr, arr+n, comp);

    if(arr[0].dist==arr[1].dist) {
        puts("Still Rozdil");
    }
    else {
        pf1(arr[0].pos);
    }
    return 0;
}
