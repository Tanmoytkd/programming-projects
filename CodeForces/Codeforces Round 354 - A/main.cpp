#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int main()
{
    int n, minpos=0, maxpos=0, mini=INT_MAX, maxi=INT_MIN, num;
    cin >> n;
    long long arr[n];
    for(int i=0; i<n; i++) {
        cin >> num;
        if(num<mini) {
            mini=num;
            minpos=i;
        }
        if(num>maxi) {
            maxi=num;
            maxpos=i;
        }
    }
    minpos=min(minpos, n-1-minpos);
    maxpos=min(maxpos, n-1-maxpos);

    int result=n-1-min(minpos, maxpos);
    cout << result << endl;
    return 0;
}
