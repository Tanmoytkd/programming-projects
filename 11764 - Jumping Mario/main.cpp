#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) {
        int n;
        cin >> n;
        int prev, curr, high=0, low=0;
        cin >> prev;
        for(int j=1; j<n; j++) {
            cin >> curr;
            if(curr>prev) high++;
            else if(curr<prev) low++;
            prev=curr;
        }
        printf("Case %d: %d %d\n", i, high, low);
    }
    return 0;
}
