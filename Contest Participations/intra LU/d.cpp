#include <bits/stdc++.h>
using namespace std;
#define mx 10000000
int dp[10000007], bit[100007], n;

void seive() {
    dp[0]=1;
    dp[1]=1;
    for(int i=4; i<=mx; i+=2) dp[i]=1;
    int stop=sqrt(mx);
    for(int i=3; i<=stop; i+=2) {
        if(dp[i]) continue;
        for(int j=i*i; j<=mx; j+=i+i) dp[j]=1;
    }
}

void update(int index, int val) {
    index++;
    while(index<=n) {
        bit[index]+=val;
        index = index+ (index & (-index));
    }
}

int query(int index) {
    int sum=0;
    index++;
    while(index>0) {
        sum+=bit[index];
        index = index - (index & (-index));
    }
    return sum;
}

int main() {
    seive();
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        arr[i]=!dp[num];
        //cout << num << " " << !dp[num] << endl;
        update(i, !dp[num]);
    }

    int q;
    scanf("%d", &q);
    while(q--) {
        int action, x, y;
        scanf("%d%d%d", &action, &x, &y);
        if(action==1) {
            if(x==1) {
                printf("%d\n", query(y-1));
            }
            else {
                printf("%d\n", query(y-1)-query(x-2));
            }
        }
        else {
            int val = arr[x-1];
            update(x-1, 0-val);

            update(x-1, !dp[y]);
            arr[x-1]=!dp[y];
        }
    }
}
