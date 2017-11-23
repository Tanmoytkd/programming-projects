#include <bits/stdc++.h>
using namespace std;
#define MX 200005

int id , tree[4*MX][3] , child[4*MX][3] , cnt[4*MX] , mx[4*MX];

int create(){
    tree[id][0] = tree[id][1] = -1;
    cnt[id] = 0;
    id++;
    return id-1;
}

void dfs(int curNode , int u){
    cnt[curNode]++;
    if(child[u][0] != -1){
        if(tree[curNode][0] == -1){
            tree[curNode][0] = create();
        }
        dfs(tree[curNode][0] , child[u][0]);
    }
    if(child[u][1] != -1){
        if(tree[curNode][1] == -1){
            tree[curNode][1] = create();
        }
        dfs(tree[curNode][1] , child[u][1]);
    }
}

void calculate(int curNode , int depth){
    mx[ cnt[curNode] ] = max( mx[ cnt[curNode] ]  , depth );
    if(tree[curNode][0] != -1){
        calculate(tree[curNode][0] , depth+1);
    }
    if(tree[curNode][1] != -1){
        calculate(tree[curNode][1] , depth+1);
    }
    return;
}

void reset(int x){
    for(int i=1; i<=x+2; i++) {
        child[i][0] = -1;
        child[i][1] = -1;
    }
}


int main(){

    int n , m , u , v , t;
    char ch;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &m);
        id = 1;

        create();

        for(int j=1; j<=m; j++) {
            scanf("%d", &n);
            reset(n);
            for(int i=1; i<n; i++) {
                scanf("%d %c %d",&u , &ch , &v);
                if(ch == 'L')child[u][0] = v;
                else child[u][1] = v;
            }
            dfs(1,1);
        }

        memset(mx, 0, sizeof mx);
        calculate(1 , 0);
        int maximum = 0;
        for(int i = m ;i >= 1;i--){
            maximum = max(maximum , mx[i]);
            mx[i] = maximum;
        }

        //cout << mx[0] << endl;
        printf("%d",mx[1]);

        for(int i=2; i<=m; i++) {
            printf(" %d",mx[i]);
        }
        printf("\n");
    }
    return 0;
}
