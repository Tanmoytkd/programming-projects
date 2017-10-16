#include <bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi() printf("hi!\n")
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));


using namespace std;
typedef long long int lint;
typedef double dbl;
 
int  n, w;
int arr[35];

vector<lint> L , H ;


void go(int i,lint sum ,int leftpart, int limit)
{
    if(sum > w) return;
    if( i > limit ){
        if(sum <= w) {
            if(leftpart )L.push_back(sum);
            else H.push_back(sum);
        }
        return;
    }
     
    go(i + 1, sum ,leftpart, limit );
    go(i + 1, sum + arr[i],leftpart, limit);
}
 
 
int bsearch(lint val)
{
    int low = 0 , high = H.size() - 1 , mid , ans =low -1;
    while (low <= high ) {
        mid = (low+high)/2;
        if(H[mid] <= val) {
            ans = mid ;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans ;
}
 
int main()
{
     
    int t , tst = 1 ;
    sf1(t);
    while (t--) {
    	L.clear();
    	H.clear();

    	sf2(n, w);
        
        for(int i=0; i<n; i++) {
        	sf1(arr[i]);
        }

        int limit = n / 2;
        go(0,0,1, limit);
        limit = n - 1 ;
        go(n/2+1 , 0 ,0 , limit);
         
        sort(L.begin(), L.end());
        sort(H.begin(), H.end());
        
        int ans = 0;
        for(int i = 0; i < L.size() ; i ++ ) {
            int k =  bsearch ( w - L[i]);
            ans += k +1;
        }
         
        printf("Case %d: %d\n", tst++ , ans );
    }
    return 0;
}