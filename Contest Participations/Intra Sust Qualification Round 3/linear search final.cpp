#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define INF 2000000000
#define PI (acos(-1.0))
#define i64 long long int
#define DBG printf("Hi\n")
#define loop(i,n) for(i =1 ; i<=n; i++)
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define maxn 200005
#define ff first
#define sc second

using namespace std ;

int main()
{
    int i , j , k , l , m , n , t=1 , tc ;

    int x1 , x2 , x3 , y1 , y2 , y3 ;

    double x , y ;

    sf("%d",&tc) ;

    while(t<=tc)
    {
        sf("%d %d %d %d",&x1,&y1,&x2,&y2) ;
        sf("%d %d",&x3,&y3) ;

        pf("Case %d: ",t++) ;

        if( (x1==x2 && y1!=y2) || (y1==y2 && x1!=x2 ) )
        {
            if(x1==x2)
            {
              //  if( x3==x1 ) pf("ambiguous ") ;
                pf("no solution no solution\n") ;

     //           pf("%d\n",x1) ;
            }
            if(y1==y2)
            {
                pf("%d ",y1) ;
                if( y3==y1 ) pf("ambiguous\n") ;
                else pf("no solution\n") ;
            }
            continue ;
        }
        if( x1==x2 && y1==y2 )
        {
            if( x3==x1 ) pf("%d ",y1) ;
            else pf("ambiguous ") ;

            if(y3==y1) pf("%d\n",x1) ;
            else pf("ambiguous\n") ;

            continue ;
        }

        else{
            y = ((y2-y1+.0)/(x2-x1+.0))*(x3-x1+.0) + (y1 + .0) ;
            x = ((x2-x1+.0)/(y2-y1+.0))*(y3-y1+.0) + (x1 + .0) ;
            pf("%0.10f %0.10f\n",y,x) ;
        }
    }

    return 0 ;
}
