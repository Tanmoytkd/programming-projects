#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a1,b1,x,y,i;

	int n;
	cin>>n;
	
	vector<int>a(n);
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	int m;
	cin>>m;
	
	vector<int>b(m);
	
	for(i=0;i<m;i++)
		cin>>b[i];
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	x=a1=2*n;
	y=b1=2*m;
	
	int j;
	
	for(i=n-1,j=m-1;i>=0;i--)
	{
		a1++;
		for(;j>=0&&b[j]>=a[i];j--)b1++;

		if(a1-b1>=x-y)x=a1,y=b1;
	}
	cout << x << ":" << y << endl;
	return 0;
}