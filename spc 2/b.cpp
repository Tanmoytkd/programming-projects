#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[1000007];

int main() {
    int n, k;

    scanf("%d%d", &n,&k);

    int arr[n+10];
    memset(cnt, 0, sizeof cnt);

    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }

    int l=1, r=1;
    int resl=1, resr=1;
    int discnt=0;
    while(r<=n) {

        if(cnt[arr[r]]==0) {
            discnt++;
        }
        cnt[arr[r]]++;
        if(discnt<=k) {
            if((r-l)>(resr-resl)) {
                resr=r;
                resl=l;
            }
            r++;
            continue;
        }
        else {
            while(discnt>k) {
                cnt[arr[l]]--;
                if(cnt[arr[l]]==0) {
                    discnt--;
                }
                l++;
            }
        }
        r++;
    }

    printf("%d %d\n", resl, resr);
    return 0;
}
