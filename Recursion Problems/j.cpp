#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,i,L[50],W[50],H[50];
    cin >> T;
    for(i=1; i<=T; i++)
    {
        cin >> L[i] >> W[i] >> H[i];
        if(L[i]==W[i]&&W[i]==H[i]&&H[i]==20)
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
