#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

#define scan_num scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &data[0][0], &data[0][2], &data[0][1], &data[1][0], &data[1][2], &data[1][1], &data[2][0], &data[2][2], &data[2][1])

char color(long long n) {
	if(n==0) return 'B';
	else if(n==1) return 'C';
	else if(n==2) return 'G';
}

int main() {
	long long data[3][3], move[3][3];
	while(scan_num==9){
		char final[4]; final[3]=0;
		bool checkbin[3], checkcol[3];

		long long movement=0;
		for(long long i=0; i<3; i++) {
			for(long long j=0; j<3; j++) {
				movement+=data[i][j];
				move[i][j]=data[i][0]+data[i][1]+data[i][2]-data[i][j]/*+data[0][j]+data[1][j]+data[2][j]-data[i][j]*/;
			}
			checkbin[i]=false;
			checkcol[i]=false;
		}

		for(long long count=0; count<3; count++) {

			long long maxi=INT_MIN, minpos, mincol, minmove;
			for(long long i=0; i<3; i++) {
				if(checkcol[i]==true) continue;
				for(long long j=0; j<3; j++) {
					if(checkbin[j]==true) continue;
					if(data[j][i]>maxi) {
						maxi=data[j][i];
						minpos=j;
						mincol=i;
						minmove=move[j][i];
					}
					if(data[j][i]==maxi && move[j][i]<minmove) {
						maxi=data[j][i];
						minpos=j;
						mincol=i;
						minmove=move[j][i];
					}
				}
			}


			final[minpos]=color(mincol);
			movement-=maxi;
			checkbin[minpos]=true;
			checkcol[mincol]=true;
		}

		pf("%s %lld\n", final, movement);
	}
	return 0;
}
