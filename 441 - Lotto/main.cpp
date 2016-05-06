#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void call(int arr[], int n, vector<int> &possible, int used[]) {
    if(possible.size()==6) {
        for(int i=0; i<6; i++) {
            printf("%d%c", possible[i], " \n"[i==5]);
        }
    }

    for(int i=0; i<n; i++) {
        if(used[i]==0) {
            used[i]=1;
            possible.push_back(arr[i]);
            call(arr, n, possible, used);
            possible.pop_back();
            for(int j=i+1; j<n; j++) {
                used[j]=0;
            }
        }
    }
}

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, start=1;

    while(1) {
        cin >> n;
        if(n==0) break;

        int arr[n], used[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            used[i]=0;
        }

        if(start) start=0;
        else cout << endl;

        vector<int> possible;
        call(arr, n, possible, used);
    }

    return 0;
}
