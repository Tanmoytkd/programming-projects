#include <bits/stdc++.h>
using namespace std;

int main(){
    int d[101];
	int n,m,a,b,C,O=-1,i,j;

	int c[101][101]={};
	cin >> n >> m;

	for(i=0;i<m;++i){
		cin >> a >> b;
		d[a]++;
		d[b]++;
		c[a][b]=1;
		c[b][a]=1;
	}

	do{
		int arr[101]={};
		C=0;
		for(i=1;i<=n;++i)
			if(d[i]==1){
				arr[C++]=i;
				--d[i];
			}
		for(i=0;i<C;++i) {
			for(j=1;j<=n;++j) {
				if(c[arr[i]][j]) {
					--d[j];
				}
			}
		}
		++O;
	} while(C>0);

	cout << O << endl;
}
