#include <bits/stdc++.h>
using namespace std;
#define mx 1000000

void calculate(long long a,long long b,long long c,long long d)
{
    int mark=0;
    long long cnew, dnew, x, y;
	for(int i=1;i<=mx;i++)
	{
		cnew=c*i;
		dnew=d*i;

		x=cnew-a;
		y=dnew-(b+x);

		if(x>=0 and y>=0) {
			cout<< x+y <<endl;
			mark=1;
			return;
		}
	}
    if(mark==0) cout<< -1 << endl;
	return;
}

int main()
{
//    #ifdef TKD
//    for(int i=1; i<100; i++) {
//        calculate(200000, 70000000, 2000000, 7000000);
//    }
//    return 0;
//    #endif

	std::ios::sync_with_stdio(false);

	long long int  test;
	cin>>test;

	while(test--)
	{
		long long x,y,p,q;
		cin>>x>>y;
		cin>>p>>q;
		calculate(x,y,p,q);
	}
	return 0;
}
