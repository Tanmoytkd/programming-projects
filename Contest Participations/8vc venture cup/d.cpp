#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
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
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
#define mx 1000007

int tree[mx*5];
int n;

int purify(int num) {
    while(num<=0) {
        num+=n;
    }

    if(num>n) {
        num = (num-1)%n+1;
    }

    return num;

}

void update(int node, int start, int fin, int i, int j) {
    if(start>j || fin<i) return;
    if(start>=i && fin<=j) {
        tree[node]++;
        return;
    }

    int nxt1=node*2;
    int nxt2=nxt1+1;

    int mid=(start+fin)/2;

    update(nxt1, start, mid, i, j);
    update(nxt2, mid+1, fin, i, j);

    tree[node]=tree[nxt1]+tree[nxt2];
}

int query(int node, int start, int fin, int i, int j) {
    if(i>j) return 0;
    if(start>j || fin<i) return 0;
    if(start>=i && fin<=j) return tree[node];

    int nxt1=node*2;
    int nxt2=nxt1+1;

    int mid=(start+fin)/2;

    int res1=query(nxt1, start, mid, i, j);
    int res2=query(nxt2, mid+1, fin, i, j);

    return res1+res2;
}

//int qr(int x, int next) {
//    if(x<=next) return query(1, 1, n, x, next)-query(1, 1, n, x, x)-query(1, 1, n, next, next);
//    else return query(1, 1, n, x, n)+ query(1, 1, n, 1, next)-query(1, 1, n, x, x)-query(1, 1, n, next, next);
//}

int qr(int start, int x, int next) {
    if(start<=next) return query(1,1,n, start, next)-query(1,1,n, x, x);
    else return query(1,1, n, start, n)+query(1, 1, n, 1, next)-query(1,1,n, x, x);
}

int main()
{
    int t, tst = 1;
    int k;
    sf2(n, k);

    int x=1;

    k=min(k, n-k);

    int dist1=k;

    int res=1;

    for(int i=0; i<n; i++) {
        int start=x-k+1;
        start=purify(start);

        int s2=x+k+1;
        s2=purify(s2);

        start=max(start, s2);

        int next=x+k-1;
        next=purify(next);

        res+=1+qr(start, x, next);
        update(1, 1, n, x, x);


        x=purify(x+k);
        cout << res << endl;
    }

    return 0;
}
