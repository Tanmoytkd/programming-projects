#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int sq[225], add[225][225];

int b_search(int * arr, int low, int high, int num) {
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==num) return mid;
    if(arr[mid]<num) return b_search(arr, mid+1, high, num);
    if(arr[mid]>num) return b_search(arr, low, mid-1, num);
}

int main() {
    for(int i=0; i<225; i++) {
        sq[i]=i*i;
    }

    for(int i=0; i<224; i++) {
        for(int j=0; j<224; j++) {
            add[i][j]= sq[i]+sq[j];
        }
    }

    int n;
    sc("%d", &n);
    while(n--) {
        int num;
        scanf("%d", &num);

        int i, j, k=-1;
        for(i=0; sq[i]<=num; i++) {
            int rest=num-sq[i];

            for(j=i; j<224; j++) {
                k=b_search(add[j], j, 223, rest);
                if(k!=-1) break;
            }
            if(k!=-1) break;
        }
        if(k==-1) pf("-1\n");
        else pf("%d %d %d\n", i, j, k);
    }

    return 0;
}
