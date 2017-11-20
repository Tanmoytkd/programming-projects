#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ara[n], arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        cin >> ara[i];
    }

    int cnt[1010];
    memset(cnt, 0, sizeof cnt);

    int err=0;
    for(int i=0; i<n; i++) {
        if(arr[i]!=ara[i]) err++;
        cnt[arr[i]]++;
    }

        int goal;
        for(int i=1; i<=n; i++) {
            if(cnt[i]==0) goal=i;
        }

        if(err==1) {
            for(int i=0; i<n; i++) {
                if(i!=0) cout << " ";
                int num = arr[i];
                if(arr[i]!=ara[i] && cnt[num]==2) {
                        cout << goal;
                }
                else cout << arr[i];
            }
            cout << endl;
        }
        else if(err==2) {
            int total=1;
            for(int i=0; i<n; i++) {
                if(i!=0) cout << " ";
                int num = arr[i];
                if(goal==ara[i] && cnt[num]==2 && total) {
                        cout << goal;
                        total--;
                }
                else cout << arr[i];
            }
            cout << endl;
        }


//    }
    return 0;
}
