 #include<bits/stdc++.h>
using namespace std;

int main()
{
    long long sum=1,t,n,x,y,c;
	cin>>n>>x>>y>>c;
	while(sum<c)
	{
		t++;
		long long emptyleft=min(x-1,t);
		long long left =  max(emptyleft-max((y+t-n),0)+1,0);
        long long right = max(emptyleft-max((t-y+1),0)+1,0);
		sum+=left+right-(emptyleft==t);
		emptyleft=min(n-x,t);

		long long top = max(emptyleft-max((y+t-n),1)+1,0), bottom = max(emptyleft-max((t-y+1),1)+1,0);
		sum+=top+bottom-(emptyleft==t);
	}
	cout<<t;
	return 0;
}
