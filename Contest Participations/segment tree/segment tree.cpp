/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define FOR(I, N) for(int I=0; I<N; I++)
#define FOR1(I, N) for(int I=1; I<=N; I++)

using namespace std;

int tree[1000001];
int arr[100001];

void build(int node, int beg, int fin) {
    if(beg==fin) {
        tree[node]=arr[beg];
        return;
    }

    int lson=node*2;
    int rson=lson+1;
    int mid=(beg+fin)/2;

    build(lson, beg, mid);
    build(rson, mid+1, fin);

    tree[node]=min(tree[lson], tree[rson]);
}

int query(int node, int beg, int fin, int i, int j) {
    if(fin<i || beg>j || i>j) {
        return INT_MAX;
    }
    if(beg>=i && fin<=j) {
        return tree[node];
    }

    int lson=node*2;
    int rson=node*2+1;
    int mid=(beg+fin)/2;

    return min( query(lson, beg, mid, i, j), query(rson, mid+1, fin, i, j) );
}

int update(int node, int beg, int fin, int i, int val) {
    if(beg==i && fin==i) {
        tree[node]=val;
        arr[i]=val;
        return tree[node];
    }

    if(fin<i || beg>i) return tree[node];

    int mid=(beg+fin)/2;

    int lson=node*2;
    int rson=lson+1;

    update(lson, beg, mid, i, val);
    update(rson, mid+1, fin, i, val);

    tree[node] = min(tree[lson], tree[rson]);
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int n;
    sf1(n);

    FOR(i, n) {
        sf1(arr[i]);
    }

    build(1, 0, n-1);

    int q;
    sf1(q);

    while(q--) {
        int i, j;
        sf2(i, j);

        if(i>j) swap(i, j);

        cout << query(1, 0, n-1, i, j) << endl;
    }


    return 0;
}
