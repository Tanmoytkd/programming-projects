#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,k;
    cin >> n >> k;

    vector<int> grph[n];

    int ds[n];

    int mx=-1;
    for(int i=0; i<n; i++)
    {
        cin >> ds[i];
        if(ds[i]>mx)
        {
            mx=ds[i];
        }
    }

    vector<int> cons[mx+1];

    for(int i=0; i<n; i++)
    {
        cons[ds[i]].push_back(i);
    }

    int ok=1;
    int es=0;

    if(cons[0].size()>1)
    {
        ok=0;
        if(!ok)
        {
            cout<< -1 << endl;;
        }
        else
        {

            cout<< es << endl;

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<grph[i].size(); j++)
                {
                    cout<< i+1 << " " << grph[i][j]+1 << endl;
                }
            }

        }

        return 0;
    }

    for(int i=1; i<=mx; i++)
    {

        if(i-1==0)
        {
            if(cons[i-1].size()*k<cons[i].size())
            {
                ok=0;
                break;
            }
        }
        else
        {
            long long df=(long long)cons[i-1].size()*(k-1);
            if(df<cons[i].size())
            {
                ok=0;
                break;
            }
        }

        int l=0;
        for(int j=0; j<cons[i].size(); j++)
        {

            int cur=cons[i-1][l];
            grph[cur].push_back(cons[i][j]);
            es++;
            l++;
            if(l==cons[i-1].size())
            {
                l=0;
            }
        }
    }

    if(!ok)
        cout<< -1 << endl;
    else
    {
        cout<< es << endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<grph[i].size(); j++)
            {
                cout<< i+1 << " " << grph[i][j]+1<< endl;
            }
        }
    }

    return 0;
}
