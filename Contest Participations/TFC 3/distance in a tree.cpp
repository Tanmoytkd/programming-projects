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
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

#define MAXN 50007
#define level 18
 
vector <int> tree[MAXN], icost[MAXN];
int depth[MAXN], totalcost[MAXN];
int parent[MAXN][level];
 
// pre-compute the depth for each node and their
// first parent(2^0th parent)
// time complexity : O(n)
void dfs(int cur, int prev, int cost)
{
    //cout << tree[cur].size() << endl;
    //cout << cur << " " << prev << " " << cost << "val" << endl;
    totalcost[cur]=cost;
    depth[cur] = ((prev!=-1) ? depth[prev]: 0)+ 1;
    parent[cur][0] = prev;
    for (int i=0; i<tree[cur].size(); i++)
    {
        //cout << i << "iter" << endl;
        if (tree[cur][i] != prev)
            dfs(tree[cur][i], cur, cost+icost[cur][i]);
    }
}
 
// Dynamic Programming Sparse Matrix Approach
// populating 2^i parent for each node
// Time complexity : O(nlogn)
void precomputeSparseMatrix(int n)
{
    for (int i=1; i<level; i++)
    {
        for (int node = 0; node < n; node++)
        {
            if (parent[node][i-1] != -1)
                parent[node][i] =
                    parent[parent[node][i-1]][i-1];
        }
    }
}
 
// Returning the LCA of u and v
// Time complexity : O(log n)
int lca(int u, int v)
{
    if (depth[v] < depth[u])
        swap(u, v);
 
    int diff = depth[v] - depth[u];
 
    // Step 1 of the pseudocode
    for (int i=0; i<level; i++)
        if ((diff>>i)&1)
            v = parent[v][i];
 
    // now depth[u] == depth[v]
    if (u == v)
        return u;
 
    // Step 2 of the pseudocode
    for (int i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
 
    return parent[u][0];
}
  
// driver function
int main()
{
    memset(parent,-1,sizeof(parent));
    int n;
    sf1(n);
    //cout << n << endl;
    FOR(i, n-1) {
        int u, v, w;
        sf3(u, v, w);
        //cout << u <<  " " << v << " " << w << endl;
        tree[u].pb(v);
        icost[u].pb(w);
        tree[v].pb(u);
        icost[v].pb(w);
    }

    depth[0] = 0;
 
    // running dfs and precalculating depth
    // of each node.
    //cout << "cheka";
    dfs(0,-1,0);
    //cout << " khai nai" << endl;
 
    // Precomputing the 2^i th ancestor for evey node
    precomputeSparseMatrix(n);
 
    int m;
    sf1(m);

    while(m--) {
        int u, v;
        sf2(u, v);

        int LCA = lca(u, v);

        printf("%d\n", totalcost[u]+totalcost[v]-2*totalcost[LCA]);
    }
    return 0;
}