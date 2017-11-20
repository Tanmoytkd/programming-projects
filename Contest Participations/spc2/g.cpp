#include<bits/stdc++.h>
#define pii pair<lint,lint>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%I64d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%I64d",&a)
#define sf2(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pcase(x) printf("Case %I64d: ",x)
#define mx 200007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(lint i=0;i<(x); i++)
#define FOR1(i, x) for(lint i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

lint n, q;
lint tree[mx*4], lazy[mx*4];
lint arr[mx];
void update(lint node, lint start, lint fin, lint i, lint j,lint val) {
    if(lazy[node]!=0) {
        tree[node]+=(fin-start+1)*lazy[node];
        if(start!=fin) {
            lint left=node*2;
            lint right=left+1;
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(fin<i || start>j) return;
    if(start==fin) {
        tree[node]+=val;;
        return;
    }
    if(start>=i && fin<=j) {
        lazy[node]+=val;
        return;
    }
    lint left=node*2;
    lint right=left+1;
    lint mid=(start+fin)/2;
    update(left, start, mid, i, j, val);
    update(right, mid+1, fin, i, j, val);
}

lint query(lint node, lint start, lint fin, lint i, lint j) {
    if(lazy[node]!=0) {
        tree[node]+=(fin-start+1)*lazy[node];
        if(start!=fin) {
            lint left=node*2;
            lint right=left+1;
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(fin<i || start>j) return 0;
    if(start>=i && fin<=j) return tree[node];
    lint left=node*2;
    lint right=left+1;
    lint mid=(start+fin)/2;
    lint res1=query(left, start, mid, i, j);
    lint res2=query(right, mid+1, fin, i, j);
    return res1+res2;
}

int main()
{
    sf2(n,q);
    FOR1(i, n) sf1ll(arr[i]);
    while(q--) {
        lint l, r;
        sf2ll(l,r);
        update(1, 1, n, l, r, 1);
    }

    lint cnt[mx];
    lint index=1;
    FOR1(i, n) {
        lint val=query(1, 1, n, i, i);
        cnt[index++]=val;
    }
    sort(cnt+1, cnt+1+n);
    sort(arr+1, arr+1+n);
    lint res=0;
    FOR1(i, n) {
        //cout << cnt[i] << " " << i << " " << arr[i] << endl;
        res+=cnt[i]*arr[i];
    }
    cout << res << endl;
    return 0;
}
