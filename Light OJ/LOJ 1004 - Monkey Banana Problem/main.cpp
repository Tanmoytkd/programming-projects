#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

long long dp[200][200], data[200][200], n, coltotal[200];

long long rec(long long row, long long column)
{

    if(column<0 || column>=coltotal[row]) return 0;

    if(row==(2*n-2))
    {
        return data[row][column];
    }

    if(dp[row][column]==-1)
    {
        long long sum1, sum2;


        if(row<n-1)
        {
            sum1=data[row][column]+rec(row+1, column);
            sum2=data[row][column]+rec(row+1, column+1);
        }
        else
        {
            sum1=data[row][column]+rec(row+1, column-1);
            sum2=data[row][column]+rec(row+1, column);
        }

        dp[row][column]=max(sum1, sum2);
    }
    return dp[row][column];
}

int main()
{
    long long test;
    cin >> test;

    for(long long t=1; t<=test; t++)
    {
        cin >> n;
        for(long long i=0; i<200; i++)
        {
            for(long long j=0; j<200; j++)
            {
                dp[i][j]=-1;
            }
        }

        long long row=0;
        for(row=0; row<n; row++)
        {
            coltotal[row]=row+1;
        }
        long long totalcol=n-1;

        while(totalcol>0)
        {
            coltotal[row]=totalcol;
            totalcol--, row++;
        }

        for(long long row=0; row<(2*n-1); row++)
        {
            for(long long column=0; column<coltotal[row]; column++)
            {
                sc("%lld", &data[row][column]);
            }
        }

//		for(long long row=0; row<(2*n-1); row++) {
//            for(long long column=0; column<coltotal[row]; column++) {
//                pf("%lld ", data[row][column]);
//            }
//            pf("\n");
//		}

        long long imax= rec(0, 0);
        pf("Case %lld: %lld\n", t, imax);
    }
    return 0;
}
