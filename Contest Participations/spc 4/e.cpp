#include <bits/stdc++.h>
using namespace std;

int tst,n, irank=15;
int arr[100],h[100];

int main() {
    cin>>tst;
    while(tst--) {
        int hostelprob=0,rankprob=0;
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            if(i>0) {
                if(arr[i]!=arr[0])
                    hostelprob=1;
            }
        }
        for(int i=0 ; i<n ; i++) {
            cin>>h[i];
            if(h[i]<irank)
                rankprob=1;
        }
        if(!(hostelprob || rankprob))
            cout<<"Party"<<endl;
        else
            cout<<"No Party"<<endl;
    }
}
