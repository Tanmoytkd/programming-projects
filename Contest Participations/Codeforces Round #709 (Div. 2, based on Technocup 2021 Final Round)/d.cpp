#include <bits/stdc++.h>
using namespace std;
#define mxn 100007

int arr[mxn];
int prv[mxn];
int nxt[mxn];
bool deleted[mxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            prv[i] = i - 1;
            nxt[i] = i + 1;
            deleted[i] = false;
        }
        nxt[n-1] = 0;

        queue<int> deletor;
        for (int i = 0; i < n; i++) {
            if (__gcd(arr[i], arr[nxt[i]]) == 1) {
                deletor.push(i);
                // cout << i << " ";
            }
        }
        // cout<< "----" << endl;

        vector<int> result;

        while (deletor.size() > 0) {
            int dpos = deletor.front();
            deletor.pop();

            if(deleted[dpos]) {
                continue;
            }

            // if(nxt[dpos] == n) {
            //     continue;
            // }

            int npos = nxt[dpos];

            if (deleted[npos]) {
                continue;
            }

            if (__gcd(arr[dpos], arr[npos]) != 1) {
                continue;
            }

            deleted[npos] = true;
            nxt[dpos] = nxt[npos];
            result.push_back(npos+1);

            deletor.push(dpos);
        }

        cout << result.size();
        for (int item: result) {
            cout << " " << item;
        }
        cout << endl;
    }

    return 0;
}