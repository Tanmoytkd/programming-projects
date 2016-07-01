#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

long long dp[200][200], data[200][200], n, coltotal[200];

long long rec(long long row, long long col) {
//    cout << row << " " << col << endl;

	if(col<0 || col>=coltotal[row]) return 0;

    if(row==(2*n-2)) {
//        cout << row << " " << col << " " << data[row][col] << endl;
        return data[row][col];
	}

	if(dp[row][col]==-1) {
        long long sum1, sum2;

//        cout << "row: " << row << " n: " << n << endl;

        if(row<n-1) {
//            cout << "TKD1" << endl;
            sum1=data[row][col]+rec(row+1, col);
            sum2=data[row][col]+rec(row+1, col+1);
        }
        else {
//            cout << "TKD2" << endl;
            sum1=data[row][col]+rec(row+1, col-1);
            sum2=data[row][col]+rec(row+1, col);
        }

        dp[row][col]=max(sum1, sum2);
	}
//	cout << row << " " << col << " " << dp[row][col] << endl;
	return dp[row][col];
}

int main() {
	long long test;
	cin >> test;

	for(long long t=1; t<=test; t++) {
		cin >> n;
		for(long long i=0; i<200; i++) {
			for(long long j=0; j<200; j++) {
				dp[i][j]=-1;
			}
		}

		long long row=0;
		for(row=0; row<n; row++) {
            coltotal[row]=row+1;
		}
		long long totalcol=n-1;
		for(; totalcol; totalcol--, row++) {
		    coltotal[row]=totalcol;
		}

		for(long long row=0; row<(2*n-1); row++) {
            for(long long col=0; col<coltotal[row]; col++) {
                sc("%lld", &data[row][col]);
            }
		}

//		for(long long row=0; row<(2*n-1); row++) {
//            for(long long col=0; col<coltotal[row]; col++) {
//                pf("%lld ", data[row][col]);
//            }
//            pf("\n");
//		}

		long long imax= rec(0, 0);
		pf("Case %lld: %lld\n", t, imax);
	}
	return 0;
}
