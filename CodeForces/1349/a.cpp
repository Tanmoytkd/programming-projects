#include <bits/stdc++.h>
using namespace std;
#define mx 200007

int arr[100007];

bool composite[mx];

void sieve() {
    composite[0]=composite[1]=1;
    for (int i = 4; i < mx; i+=2) {
        composite[i]=1;
    }

    for (int i = 3; i*i < mx; i+=2) {
        if (composite[i]) continue;
        for (int j = i+i+i; j < mx; j+= i+i) {
            composite[j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 2) {
        cout <<  ((long long) (arr[0] / __gcd(arr[0], arr[1])) * arr[1]) << endl;
        return 0;
    }

    long long res = 1;

    for (int p = 2; p * p < mx; p++) {
        if (composite[p]) {
            continue;
        }

        priority_queue<int> cnt;
        
        for (int i = 0; i < n; i++) {
            int &num = arr[i];

            int occ = 0;
            while(num % p == 0) {
                num/=p;
                occ++;
            }

            cnt.push(occ);
            while(cnt.size()>2) {
                cnt.pop();
            }
        }

        int occ = cnt.top();
        while(occ--) {
            res *= p;
        }
    }

    sort(arr, arr + n);

    bool problem = false;
    for (int i = 1; i < n; i++) {
        if (arr[i]!=arr[1]) {
            problem = true;
        }
    }

    if (!problem) {
        res *= arr[1];
    }

    cout << res << endl;

    return 0;
}