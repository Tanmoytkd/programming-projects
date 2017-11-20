#include <bits/stdc++.h>

using namespace std;

long long f(long long x, long long y)
{
    if (x%2==0)
        return x+y;
    else return x+y-1;
}


int main()
{
    int t;
    cin>>t;

    long long x, y;
    for(int tc=0; tc<t; tc++)
    {
        cin>>x>>y;

        if (x<0 || y<0)
        {
            cout<<"No Number"<<endl;
        }

        else if (x!=y && x-2!=y)
        {
            cout<<"No Number"<<endl;
        }
            else
            {
                cout<<f(x,y)<<endl;


            }
        }
    }



