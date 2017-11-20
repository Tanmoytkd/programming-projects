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
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
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

set< vector<int> > s;

vector<int> v;

struct bst {
    int val;
    bst * left, * right;

    bst(int v) {
        val=v;
        left=NULL;
        right=NULL;
    }
};

void ins(int val, bst * & node) {
    if(node==NULL) {
        bst * p = new bst(val);
        node = p;
        return;
    }

    int x = node -> val;

    if(val < x) ins(val, node->left);
    else ins(val, node->right);
}

void dfs(bst * node) {
    if(node==NULL) {
        v.pb(0);
        return;
    }

    int total = 1 + (node->left != NULL) + (node->right != NULL);
    v.pb(total);

    dfs(node->left);
    dfs(node->right);
}

int main()
{
    int t, tst = 1;
    sf1(t);

    int k;
    sf1(k);


    while(t--) {
        v.clear();
        bst * root = NULL;

        FOR(i, k) {
            int num;
            sf1(num);

            ins(num, root);
        }

        dfs(root);
        s.insert(v);
    }

    pf1(s.size());

    return 0;
}
