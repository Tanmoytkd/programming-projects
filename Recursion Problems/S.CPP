#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+5],i,j,lo,up,mid,item,check,pos;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>item;

    lo=0,up=n-1,check=0;
    while(lo<=up)
    {
        mid=(lo+up)/2;
        if(a[mid]==item)
        {
            pos=mid+1;
            check=1;
            break;
        }
        else if(item>a[mid])
        {
            lo=mid+1;
        }
        else
        {
            up=mid-1;
        }
    }
    if(check==0)
    {
        cout<<"Item Not Found"<<endl;
    }
    else
    {
        cout<<"Item Found And Position is "<<pos<<endl;
    }
    return 0;
}
