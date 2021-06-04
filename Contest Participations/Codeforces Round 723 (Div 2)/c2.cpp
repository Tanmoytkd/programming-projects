#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long total = 0;
    priority_queue<int, vector<int>, greater<int>> usedValues;

    for (int i = 0; i < n; i++) {
        if (total + arr[i] < 0) {
            if (!usedValues.empty() && usedValues.top() < arr[i]) {
                total = total - usedValues.top() + arr[i];
                usedValues.pop();
                usedValues.push(arr[i]);
            }
        } else {
            total += arr[i];
            usedValues.push(arr[i]);
        }
    }

    cout << usedValues.size() << endl;

    return 0;
}