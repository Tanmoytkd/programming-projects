#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,i,L[T],W[T],H[T];
    cin >> T;
    for(i=1; i<=T; i++)
    {
        cin >> L[i] >> W[i] >> H[i];
    }

    for(i=1; i<=T; i++)
    {
        if(L[i]==W[i]==H[i]==20)
        {
            cout << "case " << i << ": good";
        }
        else
        {
            cout << "case " << i << ": bad";
        }
    }
    return 0;
}

